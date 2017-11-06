--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -94,7 +94,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
 
@@ -666,8 +666,10 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
   }
 #endif  // OS_CHROMEOS
 
+#if 0 /* XXX */
 #if defined(TOOLKIT_VIEWS) && defined(USE_X11)
   ui::TouchFactory::SetTouchDeviceListFromCommandLine();
+#endif
 #endif
 
 #if defined(OS_MACOSX)
