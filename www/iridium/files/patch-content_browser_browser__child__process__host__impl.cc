--- content/browser/browser_child_process_host_impl.cc.orig	2024-11-04 08:56:03 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -328,6 +328,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
       switches::kTraceToConsole,
+      switches::kDisableUnveil,
+      switches::kTrk,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -659,7 +661,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
