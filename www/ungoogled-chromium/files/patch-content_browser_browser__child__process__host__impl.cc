--- content/browser/browser_child_process_host_impl.cc.orig	2024-08-26 14:40:28 UTC
+++ content/browser/browser_child_process_host_impl.cc
@@ -324,6 +324,7 @@ void BrowserChildProcessHostImpl::LaunchWithoutExtraCo
       switches::kMojoCoreLibraryPath,
       switches::kPerfettoDisableInterning,
       switches::kTraceToConsole,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -655,7 +656,7 @@ void BrowserChildProcessHostImpl::OnProcessLaunched() 
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
