--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -95,7 +95,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_FREEBSD))
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
 
