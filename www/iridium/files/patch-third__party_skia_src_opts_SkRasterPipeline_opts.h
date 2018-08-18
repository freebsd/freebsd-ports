--- third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2018-07-20 03:02:44.498284000 +0200
+++ third_party/skia/src/opts/SkRasterPipeline_opts.h	2018-07-20 03:04:09.892857000 +0200
@@ -653,7 +653,7 @@
 }
 
 SI F from_half(U16 h) {
-#if defined(__aarch64__) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(JUMPER_IS_NEON) && defined(__aarch64__) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
     return vcvt_f32_f16(h);
 
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_AVX512)
@@ -673,7 +673,7 @@
 }
 
 SI U16 to_half(F f) {
-#if defined(__aarch64__) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(JUMPER_IS_NEON) && defined(__aarch64__) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
     return vcvt_f16_f32(f);
 
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_AVX512)
