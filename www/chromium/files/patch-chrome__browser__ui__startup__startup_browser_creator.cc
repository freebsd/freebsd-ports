--- ./chrome/browser/ui/startup/startup_browser_creator.cc.orig	2014-08-20 21:02:04.000000000 +0200
+++ ./chrome/browser/ui/startup/startup_browser_creator.cc	2014-08-22 15:06:25.000000000 +0200
@@ -81,7 +81,7 @@
 #include "chromeos/chromeos_switches.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_FREEBSD))
 #include "ui/events/x/touch_factory_x11.h"
 #endif
 
