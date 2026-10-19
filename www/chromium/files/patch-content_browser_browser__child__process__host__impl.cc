--- content/browser/browser_child_process_host_impl.cc.orig	2026-10-18 13:29:39 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -308,6 +308,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kLogBestEffortTasks,
       switches::kPartitionAllocSchedulerLoopQuarantine,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -662,7 +663,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
