--- third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2018-12-03 21:20:28.000000000 +0100
+++ third_party/skia/src/opts/SkRasterPipeline_opts.h	2018-12-15 16:12:21.651812000 +0100
@@ -658,7 +658,7 @@
 }
 
 SI F from_half(U16 h) {
-#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
     return vcvt_f32_f16(h);
 
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_AVX512)
@@ -678,7 +678,7 @@
 }
 
 SI U16 to_half(F f) {
-#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
     return vcvt_f16_f32(f);
 
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_AVX512)
