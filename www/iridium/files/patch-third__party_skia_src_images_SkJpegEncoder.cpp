--- third_party/skia/src/images/SkJpegEncoder.cpp.orig	2019-03-11 22:08:28 UTC
+++ third_party/skia/src/images/SkJpegEncoder.cpp
@@ -75,9 +75,14 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
         return (transform_scanline_proc) nullptr;
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
@@ -88,6 +93,7 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
             jpegColorType = JCS_EXT_BGRA;
             numComponents = 4;
             break;
+#endif
         case kRGB_565_SkColorType:
             fProc = transform_scanline_565;
             jpegColorType = JCS_RGB;
@@ -107,6 +113,7 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
             jpegColorType = JCS_GRAYSCALE;
             numComponents = 1;
             break;
+#ifdef JCS_EXTENSIONS
         case kRGBA_F16_SkColorType:
             if (kUnpremul_SkAlphaType == srcInfo.alphaType() &&
                     options.fAlphaOption == SkJpegEncoder::AlphaOption::kBlendOnBlack) {
@@ -117,6 +124,7 @@ bool SkJpegEncoderMgr::setParams(const SkImageInfo& sr
             jpegColorType = JCS_EXT_RGBA;
             numComponents = 4;
             break;
+#endif
         default:
             return false;
     }
