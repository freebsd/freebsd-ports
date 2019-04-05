--- src/3rdparty/chromium/third_party/skia/src/images/SkJpegEncoder.cpp.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/skia/src/images/SkJpegEncoder.cpp
@@ -77,9 +77,14 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
         return transform_scanline_to_premul_legacy;
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
@@ -90,6 +95,7 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
             jpegColorType = JCS_EXT_BGRA;
             numComponents = 4;
             break;
+#endif
         case kRGB_565_SkColorType:
             fProc = transform_scanline_565;
             jpegColorType = JCS_RGB;
@@ -109,6 +115,7 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
             jpegColorType = JCS_GRAYSCALE;
             numComponents = 1;
             break;
+#ifdef JCS_EXTENSIONS
         case kRGBA_F16_SkColorType:
             if (!srcInfo.colorSpace()) {
                 return false;
@@ -124,6 +131,7 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
             jpegColorType = JCS_EXT_RGBA;
             numComponents = 4;
             break;
+#endif
         default:
             return false;
     }
