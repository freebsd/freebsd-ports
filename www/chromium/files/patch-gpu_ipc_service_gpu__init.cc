--- gpu/ipc/service/gpu_init.cc.orig	2017-06-05 19:03:08 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -84,7 +84,7 @@ void GetGpuInfoFromCommandLine(gpu::GPUInfo& gpu_info,
   }
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 void CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   TRACE_EVENT0("gpu,startup", "Collect Graphics Info");
 
@@ -111,7 +111,7 @@ void CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   }
 #endif  // defined(OS_WIN)
 }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && defined(OS_BSD)
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 bool CanAccessNvidiaDeviceFile() {
@@ -218,7 +218,7 @@ bool GpuInit::InitializeAndStartSandbox(const base::Co
   // By skipping the following code on Mac, we don't really lose anything,
   // because the basic GPU information is passed down from the host process.
   base::TimeTicks before_collect_context_graphics_info = base::TimeTicks::Now();
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   CollectGraphicsInfo(gpu_info_);
   if (gpu_info_.context_info_state == gpu::kCollectInfoFatalFailure)
     return false;
@@ -235,7 +235,7 @@ bool GpuInit::InitializeAndStartSandbox(const base::Co
     gpu::ApplyGpuDriverBugWorkarounds(
         gpu_info_, const_cast<base::CommandLine*>(&command_line));
   }
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
 
   gpu_feature_info_ = gpu::GetGpuFeatureInfo(gpu_info_, command_line);
 
