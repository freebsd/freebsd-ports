--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2020-05-25 17:49:17 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -996,7 +996,7 @@ SI F from_half(U16 h) {
 
 SI U16 to_half(F f) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
-    && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+    && ! (defined(SK_BUILD_FOR_GOOGLE3) || defined(ARMV8_OS_FREEBSD))  // Temporary workaround for some Google3 builds.
     __fp16 fp16 = __fp16(f);
     U16 u16;
     memcpy(&u16, &fp16, sizeof(U16));
