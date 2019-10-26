--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -729,7 +729,10 @@ SI F approx_powf(F x, F y) {
 }
 
 SI F from_half(U16 h) {
-#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3) && defined(__aarch64__)  // Required to build on FreeBSD aarch64
+    return vcvt_f32_f16(h);
+
+#elif defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3) // Temporary workaround for some Google3 builds.
     __fp16 fp16;
     memcpy(&fp16, &h, sizeof(U16));
     return float(fp16);
@@ -751,7 +754,10 @@ SI F from_half(U16 h) {
 }
 
 SI U16 to_half(F f) {
-#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3) && defined(__aarch64__) // Required to build on FreeBSD aarch64
+    return vcvt_f16_f32(f);
+
+#elif defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
     __fp16 fp16 = __fp16(f);
     U16 u16;
     memcpy(&u16, &fp16, sizeof(U16));
