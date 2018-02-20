--- ui/gfx/codec/jpeg_codec.cc.orig	2017-10-14 03:14:08.077073000 +0200
+++ ui/gfx/codec/jpeg_codec.cc	2017-10-14 03:25:59.561802000 +0200
@@ -219,6 +219,7 @@
     case JCS_GRAYSCALE:
     case JCS_RGB:
     case JCS_YCbCr:
+#ifdef JCS_EXTENSIONS
       // Choose an output colorspace and return if it is an unsupported one.
       // Same as JPEGCodec::Encode(), libjpeg-turbo supports all input formats
       // used by Chromium (i.e. RGBA and BGRA) and we just map the input
@@ -237,6 +238,9 @@
         NOTREACHED() << "Invalid pixel format";
         return false;
       }
+#else
+      cinfo.out_color_space = JCS_RGB;
+#endif
       break;
     case JCS_CMYK:
     case JCS_YCCK:
