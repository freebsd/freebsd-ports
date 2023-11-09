--- gfx/skia/skia/src/core/SkRasterPipeline.h.orig	2023-06-10 14:20:18.155477000 +0200
+++ gfx/skia/skia/src/core/SkRasterPipeline.h	2023-06-10 14:20:30.760915000 +0200
@@ -24,7 +24,7 @@
 struct SkImageInfo;
 struct skcms_TransferFunction;
 
-#if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32)
+#if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32) && !defined(__powerpc__)
     #define SK_HAS_MUSTTAIL 1
 #else
     #define SK_HAS_MUSTTAIL 0
