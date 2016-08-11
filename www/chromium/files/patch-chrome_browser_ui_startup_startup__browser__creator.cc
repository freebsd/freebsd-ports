--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -88,7 +88,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_FREEBSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"
 #endif
 
