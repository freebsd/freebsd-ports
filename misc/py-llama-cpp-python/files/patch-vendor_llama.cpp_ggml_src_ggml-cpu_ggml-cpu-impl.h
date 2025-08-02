--- vendor/llama.cpp/ggml/src/ggml-cpu/ggml-cpu-impl.h.orig	2025-08-02 23:17:06 UTC
+++ vendor/llama.cpp/ggml/src/ggml-cpu/ggml-cpu-impl.h
@@ -319,8 +319,6 @@ inline static int32x4_t ggml_vdotq_s32(int32x4_t acc, 
 #else
 #ifdef __POWER9_VECTOR__
 #include <altivec.h>
-#undef bool
-#define bool _Bool
 #else
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #include <intrin.h>
