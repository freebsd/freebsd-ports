--- content/renderer/render_thread_impl.cc.orig	2022-08-31 12:19:35 UTC
+++ content/renderer/render_thread_impl.cc
@@ -190,7 +190,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_OPENBSD)
 #include <malloc.h>
 #endif
 
@@ -670,7 +670,7 @@ void RenderThreadImpl::Init() {
   base::DiscardableMemoryAllocator::SetInstance(
       discardable_memory_allocator_.get());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   render_message_filter()->SetThreadType(
       ChildProcess::current()->io_thread_id(), base::ThreadType::kCompositing);
 #endif
@@ -1040,7 +1040,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
 
   const bool enable_video_decode_accelerator =
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -1051,7 +1051,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
 
   const bool enable_video_encode_accelerator =
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
