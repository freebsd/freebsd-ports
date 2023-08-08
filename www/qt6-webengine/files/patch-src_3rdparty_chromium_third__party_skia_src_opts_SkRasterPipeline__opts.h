--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2023-07-07 17:40:32 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -998,13 +998,8 @@ SI F from_half(U16 h) {
 SI F from_half(U16 h) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
     && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
-#if defined(SK_BUILD_FOR_MAC)
     return vcvt_f32_f16(h);
-#else
-    __fp16 fp16;
-    memcpy(&fp16, &h, sizeof(U16));
-    return float(fp16);
-#endif
+
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_SKX)
     return _mm256_cvtph_ps(h);
 
@@ -1024,14 +1019,8 @@ SI U16 to_half(F f) {
 SI U16 to_half(F f) {
 #if defined(JUMPER_IS_NEON) && defined(SK_CPU_ARM64) \
     && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
-#if defined(SK_BUILD_FOR_MAC)
     return vcvt_f16_f32(f);
-#else
-    __fp16 fp16 = __fp16(f);
-    U16 u16;
-    memcpy(&u16, &fp16, sizeof(U16));
-    return u16;
-#endif
+
 #elif defined(JUMPER_IS_HSW) || defined(JUMPER_IS_SKX)
     return _mm256_cvtps_ph(f, _MM_FROUND_CUR_DIRECTION);
 
