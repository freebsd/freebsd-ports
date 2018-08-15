--- third_party/blink/renderer/platform/image-encoders/image_encoder.h.orig	2018-08-13 22:29:12.687720000 +0200
+++ third_party/blink/renderer/platform/image-encoders/image_encoder.h	2018-08-13 22:29:25.094079000 +0200
@@ -7,8 +7,6 @@
 
 #include "third_party/blink/renderer/platform/platform_export.h"
 #include "third_party/blink/renderer/platform/wtf/vector.h"
-#include "third_party/libjpeg/jpeglib.h"          // for JPEG_MAX_DIMENSION
-#include "third_party/libwebp/src/webp/encode.h"  // for WEBP_MAX_DIMENSION
 #include "third_party/skia/include/core/SkStream.h"
 #include "third_party/skia/include/encode/SkJpegEncoder.h"
 #include "third_party/skia/include/encode/SkPngEncoder.h"
