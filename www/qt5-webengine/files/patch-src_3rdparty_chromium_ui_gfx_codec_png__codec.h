--- src/3rdparty/chromium/ui/gfx/codec/png_codec.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/ui/gfx/codec/png_codec.h
@@ -37,6 +37,10 @@ class CODEC_EXPORT PNGCodec {
     // This is the default Windows DIB order.
     FORMAT_BGRA,
 
+    // 4 bytes per pixel, in ARGB order in memory regardless of endianness.
+    // Only supported for decoding
+    FORMAT_ARGB,
+
     // SkBitmap format. For Encode() kN32_SkColorType (4 bytes per pixel) and
     // kAlpha_8_SkColorType (1 byte per pixel) formats are supported.
     // kAlpha_8_SkColorType gets encoded into a grayscale PNG treating alpha as
