--- tensorflow/lite/kernels/elementwise.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/lite/kernels/elementwise.cc
@@ -242,7 +242,8 @@ TfLiteStatus AbsEval(TfLiteContext* context, TfLiteNod
   const TfLiteType type = input->type;
   switch (type) {
     case kTfLiteFloat32:
-      return EvalImpl<float>(context, node, std::abs<float>, type);
+      return EvalImpl<float>(
+          context, node, [](float f) { return std::abs(f); }, type);
     case kTfLiteInt8:
       return AbsEvalQuantized<int8_t>(context, node, type);
     case kTfLiteInt16:
@@ -250,7 +251,8 @@ TfLiteStatus AbsEval(TfLiteContext* context, TfLiteNod
                  ? AbsInt16EvalImpl(context, node, type)
                  : AbsEvalQuantized<int16_t>(context, node, type);
     case kTfLiteInt32:
-      return EvalImpl<int32_t>(context, node, std::abs<int32_t>, type);
+      return EvalImpl<int32_t>(
+          context, node, [](int32_t i) { return std::abs(i); }, type);
     default:
       TF_LITE_KERNEL_LOG(context, "Current data type %s is not supported.",
                          TfLiteTypeGetName(type));
