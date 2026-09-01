--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2026-08-31 10:59:09 UTC
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -706,7 +706,7 @@ void VideoDecoderPipeline::InitializeTask(const VideoD
           &OOPVideoDecoder::GetOriginalFrame,
           base::Unretained(static_cast<OOPVideoDecoder*>(decoder_.get())));
     } else {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
       if (!main_frame_pool_) {
         get_original_frame_cb = base::NullCallback();
       } else
@@ -1165,7 +1165,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux: behavior depends on which backend the decoder represents, signaled
   // by whether it supplied a custom allocator.
   if (allocator.has_value()) {
@@ -1359,7 +1359,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The custom allocator creates frames backed by NativePixmap, which uses a
     // VideoFrame::StorageType of VideoFrame::STORAGE_DMABUFS.
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
