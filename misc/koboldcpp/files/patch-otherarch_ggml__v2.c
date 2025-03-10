--- otherarch/ggml_v2.c.orig	2024-12-11 11:02:17 UTC
+++ otherarch/ggml_v2.c
@@ -183,7 +183,7 @@ typedef double ggml_v2_float;
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #include <intrin.h>
 #else
-#if !defined(__riscv)
+#if !defined(__riscv) && (defined(__amd64__) || defined(__i386__))
 #include <immintrin.h>
 #endif
 #endif
