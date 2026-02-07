--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/gpu/webgl_image_conversion.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/gpu/webgl_image_conversion.cc
@@ -456,8 +456,8 @@ void Unpack<WebGLImageConversion::kDataFormatBGRA8, ui
   for (unsigned i = 0; i < pixels_per_row; ++i) {
     uint32_t bgra = source32[i];
 #if defined(ARCH_CPU_BIG_ENDIAN)
-    uint32_t brMask = 0xff00ff00;
-    uint32_t gaMask = 0x00ff00ff;
+    uint32_t br_mask = 0xff00ff00;
+    uint32_t ga_mask = 0x00ff00ff;
 #else
     uint32_t br_mask = 0x00ff00ff;
     uint32_t ga_mask = 0xff00ff00;
