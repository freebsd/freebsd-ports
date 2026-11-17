--- src/content/browser/browser_child_process_host_impl.cc.orig	2026-10-18 18:43:23 UTC
+++ src/content/browser/browser_child_process_host_impl.cc
@@ -301,6 +301,7 @@ void BrowserChildProcessHostImpl::Launch
       switches::kLogBestEffortTasks,
       switches::kPartitionAllocSchedulerLoopQuarantine,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -655,7 +656,7 @@ void BrowserChildProcessHostImpl::OnProc
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
