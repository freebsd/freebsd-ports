--- gpu/ipc/service/gpu_init.cc.orig	2016-12-13 14:02:18.031408000 +0000
+++ gpu/ipc/service/gpu_init.cc	2016-12-13 15:15:22.748312000 +0000
@@ -75,7 +75,7 @@
   }
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 void CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   TRACE_EVENT0("gpu,startup", "Collect Graphics Info");
 
@@ -94,7 +94,7 @@
       break;
   }
 }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && defined(OS_BSD)
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 bool CanAccessNvidiaDeviceFile() {
@@ -189,7 +189,7 @@
   // By skipping the following code on Mac, we don't really lose anything,
   // because the basic GPU information is passed down from the host process.
   base::TimeTicks before_collect_context_graphics_info = base::TimeTicks::Now();
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   CollectGraphicsInfo(gpu_info_);
   if (gpu_info_.context_info_state == gpu::kCollectInfoFatalFailure)
     return false;
@@ -206,7 +206,7 @@
     gpu::ApplyGpuDriverBugWorkarounds(
         gpu_info_, const_cast<base::CommandLine*>(&command_line));
   }
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
 
   base::TimeDelta collect_context_time =
       base::TimeTicks::Now() - before_collect_context_graphics_info;
