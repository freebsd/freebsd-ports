--- otherarch/ggml_v2.c.orig	2026-11-02 03:39:16 UTC
+++ otherarch/ggml_v2.c
@@ -179,7 +179,7 @@ typedef double ggml_v2_float;
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #include <intrin.h>
 #else
-#if !defined(__riscv)
+#if !defined(__riscv) && (defined(__amd64__) || defined(__i386__))
 #include <immintrin.h>
 #endif
 #endif
