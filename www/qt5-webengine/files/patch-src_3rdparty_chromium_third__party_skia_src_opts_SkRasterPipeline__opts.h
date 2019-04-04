--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2019-01-16 10:59:47 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -657,7 +657,10 @@ SI F approx_powf(F x, F y) {
 }
 
 SI F from_half(U16 h) {
-#if defined(__ARM_FP16_FORMAT_IEEE)
+#if defined(__ARM_FP16_FORMAT_IEEE) && defined(__aarch64__)
+    return vcvt_f32_f16(h);
+
+#elif defined(__ARM_FP16_FORMAT_IEEE)
     __fp16 fp16;
     memcpy(&fp16, &h, sizeof(U16));
     return float(fp16);
@@ -679,7 +682,10 @@ SI F from_half(U16 h) {
 }
 
 SI U16 to_half(F f) {
-#if defined(__ARM_FP16_FORMAT_IEEE)
+#if defined(__ARM_FP16_FORMAT_IEEE) && defined(__aarch64__)
+    return vcvt_f16_f32(f);
+
+#elif defined(__ARM_FP16_FORMAT_IEEE)
     __fp16 fp16 = __fp16(f);
     U16 u16;
     memcpy(&u16, &fp16, sizeof(U16));
