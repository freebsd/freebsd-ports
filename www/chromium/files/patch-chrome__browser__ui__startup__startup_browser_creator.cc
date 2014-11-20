--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -80,7 +80,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_FREEBSD))
 #include "ui/events/x/touch_factory_x11.h"
 #endif
 
