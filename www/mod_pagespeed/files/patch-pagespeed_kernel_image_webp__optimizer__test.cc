--- pagespeed/kernel/image/webp_optimizer_test.cc.orig	2017-10-06 21:38:20 UTC
+++ pagespeed/kernel/image/webp_optimizer_test.cc
@@ -121,7 +121,7 @@ class WebpScanlineOptimizerTest : public
         CreateScanlineWriter(pagespeed::image_compression::IMAGE_WEBP,
                              pixel_format, width, height, &webp_config,
                              webp_image, &message_handler_));
-    ASSERT_NE(reinterpret_cast<ScanlineWriterInterface*>(NULL),
+    ASSERT_NE(reinterpret_cast<ScanlineWriterInterface*>((void *)NULL),
               webp_writer.get());
 
     // Read the scanlines from the original image and write them to the new one.
