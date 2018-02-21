--- third_party/skia/src/images/SkJpegEncoder.cpp.orig	2017-12-28 17:28:55.164840000 +0100
+++ third_party/skia/src/images/SkJpegEncoder.cpp	2017-12-28 17:34:22.821694000 +0100
@@ -86,9 +86,14 @@
         }
     };
 
+#ifdef JCS_EXTENSIONS
     J_COLOR_SPACE jpegColorType = JCS_EXT_RGBA;
+#else
+    J_COLOR_SPACE jpegColorType = JCS_RGB;
+#endif
     int numComponents = 0;
     switch (srcInfo.colorType()) {
+#ifdef JCS_EXTENSIONS
         case kRGBA_8888_SkColorType:
             fProc = chooseProc8888();
             jpegColorType = JCS_EXT_RGBA;
@@ -99,6 +104,7 @@
             jpegColorType = JCS_EXT_BGRA;
             numComponents = 4;
             break;
+#endif
         case kRGB_565_SkColorType:
             fProc = transform_scanline_565;
             jpegColorType = JCS_RGB;
@@ -118,6 +124,7 @@
             jpegColorType = JCS_GRAYSCALE;
             numComponents = 1;
             break;
+#ifdef JCS_EXTENSIONS
         case kRGBA_F16_SkColorType:
             if (!srcInfo.colorSpace() || !srcInfo.colorSpace()->gammaIsLinear() ||
                     SkTransferFunctionBehavior::kRespect != options.fBlendBehavior) {
@@ -134,6 +141,7 @@
             jpegColorType = JCS_EXT_RGBA;
             numComponents = 4;
             break;
+#endif
         default:
             return false;
     }
