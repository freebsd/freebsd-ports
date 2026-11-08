-- workaround for https://github.com/microsoft/onnxruntime/issues/33430

--- onnxruntime/test/testdata/custom_op_get_const_input_test_library/custom_op.cc.orig	2026-10-18 10:07:51 UTC
+++ onnxruntime/test/testdata/custom_op_get_const_input_test_library/custom_op.cc
@@ -33,7 +33,7 @@ void TestCustomKernel::Compute(OrtKernelContext* conte
 }
 
 void TestCustomKernel::Compute(OrtKernelContext* context) {
-  ORT_UNUSED_PARAMETER(context);
+  //ORT_UNUSED_PARAMETER(context);
 }
 
 //
@@ -43,7 +43,7 @@ void* TestCustomOp::CreateKernel(const OrtApi& api, co
 TestCustomOp::TestCustomOp() {}
 
 void* TestCustomOp::CreateKernel(const OrtApi& api, const OrtKernelInfo* info) const {
-  ORT_UNUSED_PARAMETER(api);
+  //ORT_UNUSED_PARAMETER(api);
 #ifdef _WIN32
 #pragma warning(disable : 26409)
 #endif
