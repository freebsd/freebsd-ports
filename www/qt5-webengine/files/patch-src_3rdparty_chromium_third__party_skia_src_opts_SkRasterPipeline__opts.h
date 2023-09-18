--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2022-04-06 13:32:17 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -980,7 +980,7 @@ SI F from_half(U16 h) {
 SI F from_half(U16 h) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
     && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
-#if defined(SK_BUILD_FOR_MAC)
+#if defined(SK_BUILD_FOR_MAC) || defined(__FreeBSD__)
     return vcvt_f32_f16(h);
 #else
     __fp16 fp16;
@@ -1006,7 +1006,7 @@ SI U16 to_half(F f) {
 SI U16 to_half(F f) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
     && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
-#if defined(SK_BUILD_FOR_MAC)
+#if defined(SK_BUILD_FOR_MAC) || defined(__FreeBSD__)
     return vcvt_f16_f32(f);
 #else
     __fp16 fp16 = __fp16(f);
