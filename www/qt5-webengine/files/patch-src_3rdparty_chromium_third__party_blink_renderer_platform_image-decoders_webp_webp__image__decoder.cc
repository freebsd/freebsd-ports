--- src/3rdparty/chromium/third_party/blink/renderer/platform/image-decoders/webp/webp_image_decoder.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/image-decoders/webp/webp_image_decoder.cc
@@ -32,18 +32,20 @@
 #include "third_party/blink/renderer/platform/histogram.h"
 #include "third_party/skia/include/core/SkData.h"
 
-#if defined(ARCH_CPU_BIG_ENDIAN)
-#error Blink assumes a little-endian target.
-#endif
-
-#if SK_B32_SHIFT  // Output little-endian RGBA pixels (Android).
+#if SK_PMCOLOR_BYTE_ORDER(R, G, B, A)
 inline WEBP_CSP_MODE outputMode(bool hasAlpha) {
   return hasAlpha ? MODE_rgbA : MODE_RGBA;
 }
-#else  // Output little-endian BGRA pixels.
+#elif SK_PMCOLOR_BYTE_ORDER(B, G, R, A)
 inline WEBP_CSP_MODE outputMode(bool hasAlpha) {
   return hasAlpha ? MODE_bgrA : MODE_BGRA;
 }
+#elif SK_PMCOLOR_BYTE_ORDER(A, R, G, B)
+inline WEBP_CSP_MODE outputMode(bool hasAlpha) {
+  return hasAlpha ? MODE_Argb : MODE_ARGB;
+}
+#else
+#error Component order not supported by libwebp
 #endif
 
 namespace {
