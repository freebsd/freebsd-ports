--- content/renderer/render_thread_impl.cc.orig	2017-12-15 02:04:18.000000000 +0100
+++ content/renderer/render_thread_impl.cc	2017-12-24 14:46:13.319958000 +0100
@@ -219,12 +219,22 @@
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
@@ -929,7 +939,7 @@
   GetConnector()->BindInterface(mojom::kBrowserServiceName,
                                 mojo::MakeRequest(&storage_partition_service_));
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ChildProcess::current()->SetIOThreadPriority(base::ThreadPriority::DISPLAY);
   ChildThreadImpl::current()->SetThreadPriority(
       categorized_worker_pool_->background_worker_thread_id(),
@@ -1147,7 +1157,7 @@
       FROM_HERE,
       base::BindOnce(base::IgnoreResult(&ThreadRestrictions::SetIOAllowed),
                      false));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ChildThreadImpl::current()->SetThreadPriority(compositor_thread_->ThreadId(),
                                                 base::ThreadPriority::DISPLAY);
 #endif
@@ -1458,7 +1468,7 @@
   const bool enable_video_accelerator =
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode);
   const bool enable_gpu_memory_buffer_video_frames =
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
       !cmd_line->HasSwitch(switches::kDisableGpuCompositing) &&
       !gpu_channel_host->gpu_info().software_rendering;
@@ -1778,7 +1788,26 @@
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
