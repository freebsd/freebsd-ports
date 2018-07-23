--- content/renderer/render_thread_impl.cc.orig	2018-06-13 00:10:17.000000000 +0200
+++ content/renderer/render_thread_impl.cc	2018-07-19 12:51:34.446042000 +0200
@@ -214,12 +214,21 @@
 #include "content/common/external_ipc_dumper.h"
 #endif
 
+#if !defined(OS_BSD)
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
 #include <malloc.h>
 #endif
+#endif
 
+#if defined(OS_BSD)
+#include <stddef.h>
+#include <stdint.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 using base::ThreadRestrictions;
 using blink::WebDocument;
 using blink::WebFrame;
@@ -1096,7 +1105,7 @@
   GetConnector()->BindInterface(mojom::kBrowserServiceName,
                                 mojo::MakeRequest(&storage_partition_service_));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   render_message_filter()->SetThreadPriority(
       ChildProcess::current()->io_thread_id(), base::ThreadPriority::DISPLAY);
   render_message_filter()->SetThreadPriority(
@@ -1304,7 +1313,7 @@
                      false));
   GetContentClient()->renderer()->PostCompositorThreadCreated(
       compositor_task_runner_.get());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   render_message_filter()->SetThreadPriority(compositor_thread_->ThreadId(),
                                              base::ThreadPriority::DISPLAY);
 #endif
@@ -1584,7 +1593,7 @@
        gpu::kGpuFeatureStatusEnabled);
   const bool enable_gpu_memory_buffer_video_frames =
       !is_gpu_compositing_disabled_ &&
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames);
 #elif defined(OS_WIN)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
