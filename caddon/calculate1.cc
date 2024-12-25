#include <node.h>

namespace calculate1 {
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Number;
    using v8::Value;
    using v8::String;
    using v8::Exception;

    void Method(const FunctionCallbackInfo<Value>&args) {
        Isolate* isolate = args.GetIsolate();


        // 检查参数数量
        if (args.Length() < 2) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        int x = args[0]->NumberValue(isolate->GetCurrentContext()).FromJust();
        int y = args[1]->NumberValue(isolate->GetCurrentContext()).FromJust();


        int i;
        // double x = 100.734659, y = 353.2313423432;
        for (i=0; i < 100; i++) {
            x += y;
        }
        auto total = Number::New(isolate, x);
        args.GetReturnValue().Set(total);
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "calc1", Method);
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}