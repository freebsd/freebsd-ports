--- content/browser/browser_child_process_host_impl.cc.orig	2025-10-21 16:57:35 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -296,6 +296,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -649,7 +650,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
