--- third_party/blink/renderer/platform/image-decoders/jpeg/jpeg_image_decoder.cc.orig	2018-08-13 22:34:03.760055000 +0200
+++ third_party/blink/renderer/platform/image-decoders/jpeg/jpeg_image_decoder.cc	2018-08-13 22:41:48.671075000 +0200
@@ -643,6 +643,9 @@
   IntSize UvSize() const { return uv_size_; }
 
  private:
+#if defined(USE_SYSTEM_LIBJPEG)
+  NO_SANITIZE_CFI_ICALL
+#endif
   JSAMPARRAY AllocateSampleArray() {
 // Some output color spaces don't need the sample array: don't allocate in that
 // case.
