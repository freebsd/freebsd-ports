--- content/browser/browser_child_process_host_impl.cc.orig	2024-06-25 12:08:48 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -330,6 +330,8 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kMojoCoreLibraryPath,
       switches::kPerfettoDisableInterning,
       switches::kTraceToConsole,
+      switches::kDisableUnveil,
+      switches::kTrk,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -658,7 +660,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
