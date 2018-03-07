--- content/renderer/render_thread_impl.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/renderer/render_thread_impl.cc	2018-03-04 01:40:50.991485000 +0100
@@ -224,12 +224,22 @@
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
+#include <sys/user.h>
+#endif
+
 using base::ThreadRestrictions;
 using blink::WebDocument;
 using blink::WebFrame;
@@ -973,7 +983,7 @@
   GetConnector()->BindInterface(mojom::kBrowserServiceName,
                                 mojo::MakeRequest(&storage_partition_service_));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   render_message_filter()->SetThreadPriority(
       ChildProcess::current()->io_thread_id(), base::ThreadPriority::DISPLAY);
   render_message_filter()->SetThreadPriority(
@@ -1184,7 +1194,7 @@
       FROM_HERE,
       base::BindOnce(base::IgnoreResult(&ThreadRestrictions::SetIOAllowed),
                      false));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   render_message_filter()->SetThreadPriority(compositor_thread_->ThreadId(),
                                              base::ThreadPriority::DISPLAY);
 #endif
@@ -1499,7 +1509,7 @@
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode);
   const bool enable_gpu_memory_buffer_video_frames =
       !is_gpu_compositing_disabled_ &&
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames);
 #elif defined(OS_WIN)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
@@ -1847,7 +1857,26 @@
       blink_stats.blink_gc_total_allocated_bytes / 1024;
   std::unique_ptr<base::ProcessMetrics> metric(
       base::ProcessMetrics::CreateCurrentProcessMetrics());
+#if defined(OS_BSD)
+  struct kinfo_proc *info;
+  size_t length, malloc_usage = 0;
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid(),
+      sizeof(struct kinfo_proc), 0 };
+  
+  if (sysctl(mib, arraysize(mib), NULL, &length, NULL, 0) < 0)
+      return -1;
+
+  info = (struct kinfo_proc *)malloc(length);
+
+  mib[5] = (length / sizeof(struct kinfo_proc));
+
+  if (!sysctl(mib, arraysize(mib), info, &length, NULL, 0))
+      malloc_usage = (((unsigned long long)(info->ki_tsize + info->ki_dsize + info->ki_ssize)*getpagesize()));
+
+  free(info);
+#else
   size_t malloc_usage = metric->GetMallocUsage();
+#endif
   memory_metrics->malloc_mb = malloc_usage / 1024 / 1024;
 
   discardable_memory::ClientDiscardableSharedMemoryManager::Statistics
