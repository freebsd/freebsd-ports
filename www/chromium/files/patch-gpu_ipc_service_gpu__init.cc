--- gpu/ipc/service/gpu_init.cc.orig	2017-03-09 20:04:33 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -76,7 +76,7 @@ void GetGpuInfoFromCommandLine(gpu::GPUI
   }
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 void CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   TRACE_EVENT0("gpu,startup", "Collect Graphics Info");
 
@@ -95,7 +95,7 @@ void CollectGraphicsInfo(gpu::GPUInfo& g
       break;
   }
 }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && defined(OS_BSD)
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 bool CanAccessNvidiaDeviceFile() {
@@ -194,7 +194,7 @@ bool GpuInit::InitializeAndStartSandbox(
   // By skipping the following code on Mac, we don't really lose anything,
   // because the basic GPU information is passed down from the host process.
   base::TimeTicks before_collect_context_graphics_info = base::TimeTicks::Now();
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   CollectGraphicsInfo(gpu_info_);
   if (gpu_info_.context_info_state == gpu::kCollectInfoFatalFailure)
     return false;
@@ -211,7 +211,7 @@ bool GpuInit::InitializeAndStartSandbox(
     gpu::ApplyGpuDriverBugWorkarounds(
         gpu_info_, const_cast<base::CommandLine*>(&command_line));
   }
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
 
   base::TimeDelta collect_context_time =
       base::TimeTicks::Now() - before_collect_context_graphics_info;
