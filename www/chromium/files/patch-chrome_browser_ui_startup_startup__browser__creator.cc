--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -303,7 +303,7 @@ bool IsSilentLaunchEnabled(const base::CommandLine& co
 // true, send a warning if guest mode is requested but not allowed by policy.
 bool IsGuestModeEnforced(const base::CommandLine& command_line,
                          bool show_warning) {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   PrefService* service = g_browser_process->local_state();
   DCHECK(service);
 
@@ -687,12 +687,14 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
   }
 #endif  // OS_CHROMEOS
 
+#if 0 /* XXX */
 #if defined(TOOLKIT_VIEWS) && defined(USE_X11)
   // TODO(https://crbug.com/1097696): make it available on ozone/linux.
   if (!features::IsUsingOzonePlatform())
     ui::TouchFactory::SetTouchDeviceListFromCommandLine();
   else
     NOTIMPLEMENTED_LOG_ONCE();
+#endif
 #endif
 
 #if defined(OS_MACOSX)
