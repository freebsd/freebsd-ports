--- src/3rdparty/chromium/media/gpu/chromeos/video_decoder_pipeline.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/media/gpu/chromeos/video_decoder_pipeline.cc
@@ -213,7 +213,7 @@ std::unique_ptr<VideoDecoder> VideoDecoderPipeline::Cr
 #if BUILDFLAG(USE_VAAPI)
     create_decoder_function_cb = base::BindOnce(&VaapiVideoDecoder::Create);
 #elif BUILDFLAG(USE_V4L2_CODEC) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD))
     create_decoder_function_cb = base::BindOnce(&V4L2VideoDecoder::Create);
 #else
     return nullptr;
@@ -860,14 +860,14 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_VAAPI)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_VAAPI)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
   CHECK(main_frame_pool_->AsPlatformVideoFramePool());
   main_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
       *allocator);
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
   // Linux w/ V4L2 should not use a custom allocator
   // Only tested with video_decode_accelerator_tests
   // TODO(wenst@) Test with full Chromium Browser
@@ -997,7 +997,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
         *allocator);
 #endif
