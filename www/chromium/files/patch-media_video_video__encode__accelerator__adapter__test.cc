--- media/video/video_encode_accelerator_adapter_test.cc.orig	2021-04-14 18:41:06 UTC
+++ media/video/video_encode_accelerator_adapter_test.cc
@@ -285,7 +285,7 @@ TEST_P(VideoEncodeAcceleratorAdapterTest, TwoFramesRes
 
   vea()->SetEncodingCallback(base::BindLambdaForTesting(
       [&](BitstreamBuffer&, bool keyframe, scoped_refptr<VideoFrame> frame) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         EXPECT_EQ(frame->format(),
                   IsYuvPlanar(pixel_format) ? pixel_format : PIXEL_FORMAT_I420);
 #else
