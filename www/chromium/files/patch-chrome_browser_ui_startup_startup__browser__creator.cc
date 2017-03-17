--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -95,7 +95,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
 
@@ -657,9 +657,11 @@ bool StartupBrowserCreator::ProcessCmdLi
   }
 #endif  // OS_CHROMEOS
 
+#if 0 /* XXX */
 #if defined(TOOLKIT_VIEWS) && defined(USE_X11)
   ui::TouchFactory::SetTouchDeviceListFromCommandLine();
 #endif
+#endif
 
 #if defined(OS_MACOSX)
   if (web_app::MaybeRebuildShortcut(command_line))
