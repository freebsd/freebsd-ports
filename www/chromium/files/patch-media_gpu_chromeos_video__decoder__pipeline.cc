--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2022-07-22 17:30:31 UTC
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -656,7 +656,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
@@ -678,7 +678,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
 #error "Unsupported platform"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // viable_candidate should always be set unless using L1 protected content,
   // which isn't an option on linux.
   CHECK(viable_candidate);
