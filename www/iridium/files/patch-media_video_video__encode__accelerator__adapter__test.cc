--- media/video/video_encode_accelerator_adapter_test.cc.orig	2024-08-27 06:28:16 UTC
+++ media/video/video_encode_accelerator_adapter_test.cc
@@ -457,7 +457,7 @@ TEST_P(VideoEncodeAcceleratorAdapterTest, TwoFramesRes
       CreateGreenFrame(large_size, pixel_format, base::Milliseconds(2));
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (pixel_format != PIXEL_FORMAT_I420 || !small_frame->IsMappable())
     expected_input_format = PIXEL_FORMAT_NV12;
 #endif
