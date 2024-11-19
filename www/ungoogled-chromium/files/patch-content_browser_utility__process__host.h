--- content/browser/utility_process_host.h.orig	2024-11-16 12:20:41 UTC
+++ content/browser/utility_process_host.h
@@ -34,7 +34,7 @@ class Thread;
 }  // namespace base
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 namespace viz {
 class GpuClient;
 }  // namespace viz
@@ -202,7 +202,7 @@ class CONTENT_EXPORT UtilityProcessHost
   LaunchState launch_state_ = LaunchState::kLaunchInProgress;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool allowed_gpu_;
   std::unique_ptr<viz::GpuClient, base::OnTaskRunnerDeleter> gpu_client_;
 #endif
