--- content/renderer/render_thread_impl.cc.orig	2021-04-14 18:41:03 UTC
+++ content/renderer/render_thread_impl.cc
@@ -175,7 +175,7 @@
 
 #if defined(OS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !defined(OS_BSD)
 #include <malloc.h>
 #endif
 
@@ -686,7 +686,7 @@ void RenderThreadImpl::Init() {
   DCHECK(parsed_num_raster_threads) << string_value;
   DCHECK_GT(num_raster_threads, 0);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   categorized_worker_pool_->SetBackgroundingCallback(
       main_thread_scheduler_->DefaultTaskRunner(),
       base::BindOnce(
@@ -709,7 +709,7 @@ void RenderThreadImpl::Init() {
   base::DiscardableMemoryAllocator::SetInstance(
       discardable_memory_allocator_.get());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           blink::features::kBlinkCompositorUseDisplayThreadPriority)) {
     render_message_filter()->SetThreadPriority(
@@ -1038,11 +1038,11 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
   const bool enable_video_accelerator =
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
       (gpu_channel_host->gpu_feature_info()
            .status_values[gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE] ==
        gpu::kGpuFeatureStatusEnabled);
@@ -1052,7 +1052,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames);
 #else
       cmd_line->HasSwitch(switches::kEnableGpuMemoryBufferVideoFrames);
-#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         // defined(OS_WIN)
   const bool enable_media_stream_gpu_memory_buffers =
       enable_gpu_memory_buffers &&
