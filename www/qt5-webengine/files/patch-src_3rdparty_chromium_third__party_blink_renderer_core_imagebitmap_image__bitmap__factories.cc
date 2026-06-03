--- src/3rdparty/chromium/third_party/blink/renderer/core/imagebitmap/image_bitmap_factories.cc.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/imagebitmap/image_bitmap_factories.cc
@@ -63,7 +63,7 @@ namespace {
 
 namespace {
 // This enum is used in a UMA histogram.
-enum CreateImageBitmapSource {
+enum CreateImageBitmapSource : uint8_t {
   kCreateImageBitmapSourceBlob = 0,
   kCreateImageBitmapSourceImageBitmap = 1,
   kCreateImageBitmapSourceImageData = 2,
