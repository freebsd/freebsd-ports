--- src/3rdparty/chromium/media/video/video_encode_accelerator_adapter_test.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/video/video_encode_accelerator_adapter_test.cc
@@ -378,7 +378,7 @@ TEST_P(VideoEncodeAcceleratorAdapterTest, TwoFramesRes
 
   vea()->SetEncodingCallback(base::BindLambdaForTesting(
       [&](BitstreamBuffer&, bool keyframe, scoped_refptr<VideoFrame> frame) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         EXPECT_EQ(frame->format(),
                   IsYuvPlanar(pixel_format) ? pixel_format : PIXEL_FORMAT_I420);
 #else
