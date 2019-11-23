--- src/3rdparty/chromium/third_party/blink/renderer/platform/image-decoders/jpeg/jpeg_image_decoder.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/image-decoders/jpeg/jpeg_image_decoder.cc
@@ -49,23 +49,30 @@ extern "C" {
 #include <setjmp.h>
 }
 
-#if defined(ARCH_CPU_BIG_ENDIAN)
-#error Blink assumes a little-endian target.
-#endif
-
 #if defined(JCS_ALPHA_EXTENSIONS)
 #define TURBO_JPEG_RGB_SWIZZLE
-#if SK_B32_SHIFT  // Output little-endian RGBA pixels (Android).
+#if SK_PMCOLOR_BYTE_ORDER(R, G, B, A)
 inline J_COLOR_SPACE rgbOutputColorSpace() {
   return JCS_EXT_RGBA;
 }
-#else  // Output little-endian BGRA pixels.
+#elif SK_PMCOLOR_BYTE_ORDER(B, G, R, A)
 inline J_COLOR_SPACE rgbOutputColorSpace() {
   return JCS_EXT_BGRA;
 }
+#elif SK_PMCOLOR_BYTE_ORDER(A, R, G, B)
+inline J_COLOR_SPACE rgbOutputColorSpace() {
+  return JCS_EXT_ARGB;
+}
+#elif SK_PMCOLOR_BYTE_ORDER(A, B, G, R)
+inline J_COLOR_SPACE rgbOutputColorSpace() {
+  return JCS_EXT_ABGR;
+}
+#else
+#error Component order not supported by libjpeg_turbo
 #endif
 inline bool turboSwizzled(J_COLOR_SPACE colorSpace) {
-  return colorSpace == JCS_EXT_RGBA || colorSpace == JCS_EXT_BGRA;
+  return colorSpace == JCS_EXT_RGBA || colorSpace == JCS_EXT_BGRA ||
+    colorSpace == JCS_EXT_ABGR || colorSpace == JCS_EXT_ARGB;
 }
 #else
 inline J_COLOR_SPACE rgbOutputColorSpace() {
