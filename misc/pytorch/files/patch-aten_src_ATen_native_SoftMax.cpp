--- aten/src/ATen/native/SoftMax.cpp.orig	2022-12-29 23:05:30 UTC
+++ aten/src/ATen/native/SoftMax.cpp
@@ -132,7 +132,7 @@ void host_softmax(
     const Tensor& input,
     const int64_t dim,
     bool* mask = nullptr,
-    const c10::optional<int64_t> mask_type_ = NULL) {
+    const c10::optional<int64_t> mask_type_ = 0) {
 
   if (MaskedSoftMax) {
     TORCH_CHECK(mask_type_.has_value(), "Mask Type should be defined");
