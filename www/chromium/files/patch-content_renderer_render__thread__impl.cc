--- content/renderer/render_thread_impl.cc.orig	2022-06-17 14:20:10 UTC
+++ content/renderer/render_thread_impl.cc
@@ -190,7 +190,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_OPENBSD)
 #include <malloc.h>
 #endif
 
@@ -717,7 +717,7 @@ void RenderThreadImpl::Init() {
   DCHECK(parsed_num_raster_threads) << string_value;
   DCHECK_GT(num_raster_threads, 0);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   categorized_worker_pool_->SetBackgroundingCallback(
       main_thread_scheduler_->DefaultTaskRunner(),
       base::BindOnce(
@@ -740,7 +740,7 @@ void RenderThreadImpl::Init() {
   base::DiscardableMemoryAllocator::SetInstance(
       discardable_memory_allocator_.get());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           blink::features::kBlinkCompositorUseDisplayThreadPriority)) {
     render_message_filter()->SetThreadPriority(
@@ -1099,7 +1099,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
 
   const bool enable_video_decode_accelerator =
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -1110,7 +1110,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
 
   const bool enable_video_encode_accelerator =
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
