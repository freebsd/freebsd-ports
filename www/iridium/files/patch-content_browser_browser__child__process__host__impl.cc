--- content/browser/browser_child_process_host_impl.cc.orig	2026-02-16 10:45:29 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -292,6 +292,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
+      switches::kTrk,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -649,7 +651,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
