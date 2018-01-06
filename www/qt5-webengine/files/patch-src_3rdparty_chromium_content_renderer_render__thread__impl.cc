--- src/3rdparty/chromium/content/renderer/render_thread_impl.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/renderer/render_thread_impl.cc
@@ -206,11 +206,13 @@
 #include "content/common/external_ipc_dumper.h"
 #endif
 
+#if !defined(OS_BSD)
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
 #include <malloc.h>
 #endif
+#endif
 
 using base::ThreadRestrictions;
 using blink::WebDocument;
@@ -1488,7 +1490,7 @@ media::GpuVideoAcceleratorFactories* Ren
   const bool enable_video_accelerator =
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode);
   const bool enable_gpu_memory_buffer_video_frames =
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
       !cmd_line->HasSwitch(switches::kDisableGpuCompositing) &&
       !gpu_channel_host->gpu_info().software_rendering;
@@ -1846,6 +1848,8 @@ void RenderThreadImpl::RecordPurgeAndSus
 #else
   size_t malloc_usage = minfo.hblkhd + minfo.arena;
 #endif
+#elif defined(OS_BSD)
+  size_t malloc_usage = 0;
 #else
   size_t malloc_usage = GetMallocUsage();
 #endif
