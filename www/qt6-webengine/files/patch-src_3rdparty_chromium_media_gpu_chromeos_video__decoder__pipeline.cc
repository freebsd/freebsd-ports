--- src/3rdparty/chromium/media/gpu/chromeos/video_decoder_pipeline.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/media/gpu/chromeos/video_decoder_pipeline.cc
@@ -1159,7 +1159,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_VAAPI)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_VAAPI)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
@@ -1168,7 +1168,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
   // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
   main_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
       *allocator, VideoFrame::STORAGE_DMABUFS);
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
   // Linux w/ V4L2 should not use a custom allocator
   // Only tested with video_decode_accelerator_tests
   // TODO(wenst@) Test with full Chromium Browser
@@ -1350,7 +1350,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The custom allocator creates frames backed by NativePixmap, which uses a
     // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
