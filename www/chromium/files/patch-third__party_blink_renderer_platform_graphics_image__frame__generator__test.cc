--- third_party/blink/renderer/platform/graphics/image_frame_generator_test.cc.orig	2020-07-13 10:03:26 UTC
+++ third_party/blink/renderer/platform/graphics/image_frame_generator_test.cc
@@ -244,14 +244,14 @@ static void DecodeThreadMain(ImageFrameGenerator* gene
                             cc::PaintImage::kDefaultGeneratorClientId);
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 // TODO(crbug.com/948641)
 #define MAYBE_incompleteDecodeBecomesCompleteMultiThreaded \
   DISABLED_incompleteDecodeBecomesCompleteMultiThreaded
 #else
 #define MAYBE_incompleteDecodeBecomesCompleteMultiThreaded \
   incompleteDecodeBecomesCompleteMultiThreaded
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 TEST_F(ImageFrameGeneratorTest,
        MAYBE_incompleteDecodeBecomesCompleteMultiThreaded) {
   SetFrameStatus(ImageFrame::kFramePartial);
