--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2022-02-07 13:39:41 UTC
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -644,7 +644,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
     }
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
@@ -665,7 +665,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
 #error "Unsupported platform"
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // viable_candidate should always be set unless using L1 protected content,
   // which isn't an option on linux or lacros.
   CHECK(viable_candidate);
