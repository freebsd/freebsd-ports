--- content/browser/utility_process_host.h.orig	2023-06-05 19:39:05 UTC
+++ content/browser/utility_process_host.h
@@ -39,7 +39,7 @@ namespace base {
 class Thread;
 }  // namespace base
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace viz {
 class GpuClient;
 }  // namespace viz
@@ -210,7 +210,7 @@ class CONTENT_EXPORT UtilityProcessHost
   std::vector<RunServiceDeprecatedCallback> pending_run_service_callbacks_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<viz::GpuClient, base::OnTaskRunnerDeleter> gpu_client_;
 #endif
 
