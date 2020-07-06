--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2020-05-31 18:04:09 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -988,9 +988,7 @@ SI F approx_powf(F x, F y) {
 SI F from_half(U16 h) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
     && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
-    __fp16 fp16;
-    memcpy(&fp16, &h, sizeof(U16));
-    return float(fp16);
+    return vcvt_f32_f16(h);
 
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_AVX512)
     return _mm256_cvtph_ps(h);
@@ -1011,10 +1009,7 @@ SI F from_half(U16 h) {
 SI U16 to_half(F f) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
     && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
-    __fp16 fp16 = __fp16(f);
-    U16 u16;
-    memcpy(&u16, &fp16, sizeof(U16));
-    return u16;
+    return vcvt_f16_f32(f);
 
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_AVX512)
     return _mm256_cvtps_ph(f, _MM_FROUND_CUR_DIRECTION);
