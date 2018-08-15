--- third_party/blink/renderer/platform/image-encoders/image_encoder.cc.orig	2018-08-13 22:25:20.364425000 +0200
+++ third_party/blink/renderer/platform/image-encoders/image_encoder.cc	2018-08-13 22:28:52.206462000 +0200
@@ -4,6 +4,17 @@
 
 #include "third_party/blink/renderer/platform/image-encoders/image_encoder.h"
 
+#include "build/build_config.h"
+
+#if defined(OS_WIN)
+#include <basetsd.h>  // Included before jpeglib.h because of INT32 clash
+#endif                // OS_WIN
+#include <stdio.h>    // Needed by jpeglib.h
+
+#include "jpeglib.h"  // for JPEG_MAX_DIMENSION
+
+#include "third_party/libwebp/src/webp/encode.h"  // for WEBP_MAX_DIMENSION
+
 namespace blink {
 
 bool ImageEncoder::Encode(Vector<unsigned char>* dst,
