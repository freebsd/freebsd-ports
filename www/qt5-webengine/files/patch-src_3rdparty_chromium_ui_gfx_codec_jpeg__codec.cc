--- src/3rdparty/chromium/ui/gfx/codec/jpeg_codec.cc.orig	2019-05-23 14:39:34.000000000 +0200
+++ src/3rdparty/chromium/ui/gfx/codec/jpeg_codec.cc	2019-10-27 22:18:49.231847000 +0100
@@ -207,16 +207,17 @@
     case JCS_GRAYSCALE:
     case JCS_RGB:
     case JCS_YCbCr:
+#ifdef JCS_EXTENSIONS
       // Choose an output colorspace and return if it is an unsupported one.
       // Same as JPEGCodec::Encode(), libjpeg-turbo supports all input formats
       // used by Chromium (i.e. RGBA and BGRA) and we just map the input
       // parameters to a colorspace.
       if (format == FORMAT_RGBA ||
-          (format == FORMAT_SkBitmap && SK_R32_SHIFT == 0)) {
+          (format == FORMAT_SkBitmap && SK_PMCOLOR_BYTE_ORDER(R, G, B, A))) {
         cinfo->out_color_space = JCS_EXT_RGBX;
         cinfo->output_components = 4;
       } else if (format == FORMAT_BGRA ||
-                 (format == FORMAT_SkBitmap && SK_B32_SHIFT == 0)) {
+                 (format == FORMAT_SkBitmap && SK_PMCOLOR_BYTE_ORDER(B, G, R, A))) {
         cinfo->out_color_space = JCS_EXT_BGRX;
         cinfo->output_components = 4;
       } else {
@@ -224,6 +225,9 @@
         return false;
       }
       break;
+#else
+      cinfo.out_color_space = JCS_RGB;
+#endif
     case JCS_CMYK:
     case JCS_YCCK:
     default:
