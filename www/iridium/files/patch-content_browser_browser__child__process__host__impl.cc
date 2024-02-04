--- content/browser/browser_child_process_host_impl.cc.orig	2024-02-04 14:46:08 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -321,6 +321,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kDisableBestEffortTasks,
       switches::kDisableLogging,
       switches::kEnableLogging,
+      switches::kDisableUnveil,
+      switches::kTrk,
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kLogFile,
@@ -630,7 +632,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
