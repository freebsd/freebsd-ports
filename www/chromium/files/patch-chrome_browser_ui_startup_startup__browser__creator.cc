--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2019-06-04 18:55:18 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -82,7 +82,7 @@
 #include "chrome/browser/ui/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
 
@@ -652,8 +652,10 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
   }
 #endif  // OS_CHROMEOS
 
+#if 0 /* XXX */
 #if defined(TOOLKIT_VIEWS) && defined(USE_X11)
   ui::TouchFactory::SetTouchDeviceListFromCommandLine();
+#endif
 #endif
 
 #if defined(OS_MACOSX)
