--- aten/src/ATen/native/transformers/attention.cpp.orig	2022-12-29 23:18:12 UTC
+++ aten/src/ATen/native/transformers/attention.cpp
@@ -118,7 +118,7 @@ Tensor masked_softmax(
     Tensor& attn_scores,
     c10::optional<Tensor> attn_mask,
     const Tensor& query,
-    c10::optional<int64_t> mask_type = NULL) {
+    c10::optional<int64_t> mask_type = 0) {
   if (query.is_nested() && !attn_mask) {
     return at::_nested_tensor_softmax_with_shape(attn_scores, query);
   }
