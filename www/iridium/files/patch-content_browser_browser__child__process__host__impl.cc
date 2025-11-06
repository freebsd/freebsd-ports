--- content/browser/browser_child_process_host_impl.cc.orig	2025-11-06 10:11:34 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -296,6 +296,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
+      switches::kTrk,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -660,7 +662,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
