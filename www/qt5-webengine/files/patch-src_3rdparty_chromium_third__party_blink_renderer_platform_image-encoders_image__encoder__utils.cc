--- src/3rdparty/chromium/third_party/blink/renderer/platform/image-encoders/image_encoder_utils.cc.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/image-encoders/image_encoder_utils.cc
@@ -16,7 +16,7 @@ namespace {
 
 namespace {
 // This enum is used in a UMA histogram; the values should not be changed.
-enum RequestedImageMimeType {
+enum RequestedImageMimeType : uint8_t {
   kRequestedImageMimeTypePng = 0,
   kRequestedImageMimeTypeJpeg = 1,
   kRequestedImageMimeTypeWebp = 2,
