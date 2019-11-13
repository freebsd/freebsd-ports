--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2019-10-21 19:06:24 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -85,7 +85,7 @@
 #include "chrome/browser/ui/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
 
@@ -295,7 +295,7 @@ bool IsSilentLaunchEnabled(const base::CommandLine& co
 // true, send a warning if guest mode is requested but not allowed by policy.
 bool IsGuestModeEnforced(const base::CommandLine& command_line,
                          bool show_warning) {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   PrefService* service = g_browser_process->local_state();
   DCHECK(service);
 
@@ -666,8 +666,10 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
   }
 #endif  // OS_CHROMEOS
 
+#if 0 /* XXX */
 #if defined(TOOLKIT_VIEWS) && defined(USE_X11)
   ui::TouchFactory::SetTouchDeviceListFromCommandLine();
+#endif
 #endif
 
 #if defined(OS_MACOSX)
