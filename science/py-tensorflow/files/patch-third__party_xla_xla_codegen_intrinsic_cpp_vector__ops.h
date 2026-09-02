--- third_party/xla/xla/codegen/intrinsic/cpp/vector_ops.h.orig	2026-03-04 22:33:50 UTC
+++ third_party/xla/xla/codegen/intrinsic/cpp/vector_ops.h
@@ -16,7 +16,8 @@
 #ifndef XLA_CODEGEN_INTRINSIC_CPP_VECTOR_OPS_H_
 #define XLA_CODEGEN_INTRINSIC_CPP_VECTOR_OPS_H_
 
-#if defined(__has_attribute) && __has_attribute(ext_vector_type) && \
+#if defined(__FLT16_MANT_DIG__) && \
+    defined(__has_attribute) && __has_attribute(ext_vector_type) && \
     defined(__has_builtin) && __has_builtin(__builtin_vectorelements)
 
 #include <cstddef>
