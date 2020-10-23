--- ui/gfx/codec/jpeg_codec.cc.orig	2020-09-08 19:14:28 UTC
+++ ui/gfx/codec/jpeg_codec.cc
@@ -208,6 +208,7 @@ bool JPEGCodec::Decode(const unsigned char* input, siz
     case JCS_GRAYSCALE:
     case JCS_RGB:
     case JCS_YCbCr:
+#ifdef JCS_EXTENSIONS
       // Choose an output colorspace and return if it is an unsupported one.
       // Same as JPEGCodec::Encode(), libjpeg-turbo supports all input formats
       // used by Chromium (i.e. RGBA and BGRA) and we just map the input
@@ -224,6 +225,9 @@ bool JPEGCodec::Decode(const unsigned char* input, siz
         NOTREACHED() << "Invalid pixel format";
         return false;
       }
+#else
+      cinfo.out_color_space = JCS_RGB;
+#endif
       break;
     case JCS_CMYK:
     case JCS_YCCK:
