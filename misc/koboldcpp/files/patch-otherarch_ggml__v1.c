--- otherarch/ggml_v1.c.orig	2024-12-11 11:02:13 UTC
+++ otherarch/ggml_v1.c
@@ -151,7 +151,7 @@ typedef double ggml_v1_float;
 #undef bool
 #define bool _Bool
 #else
-#if !defined(__riscv)
+#if !defined(__riscv) && (defined(__amd64__) || defined(__i386__))
 #include <immintrin.h>
 #endif
 #endif
