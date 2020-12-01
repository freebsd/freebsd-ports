--- third_party/blink/renderer/platform/graphics/image_frame_generator_test.cc.orig	2020-11-13 06:36:48 UTC
+++ third_party/blink/renderer/platform/graphics/image_frame_generator_test.cc
@@ -244,14 +244,14 @@ static void DecodeThreadMain(ImageFrameGenerator* gene
                             cc::PaintImage::kDefaultGeneratorClientId);
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // TODO(crbug.com/948641)
 #define MAYBE_incompleteDecodeBecomesCompleteMultiThreaded \
   DISABLED_incompleteDecodeBecomesCompleteMultiThreaded
 #else
 #define MAYBE_incompleteDecodeBecomesCompleteMultiThreaded \
   incompleteDecodeBecomesCompleteMultiThreaded
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 TEST_F(ImageFrameGeneratorTest,
        MAYBE_incompleteDecodeBecomesCompleteMultiThreaded) {
   SetFrameStatus(ImageFrame::kFramePartial);
