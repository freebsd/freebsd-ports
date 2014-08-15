--- ./chrome/browser/ui/startup/startup_browser_creator.cc.orig	2014-08-12 21:01:35.000000000 +0200
+++ ./chrome/browser/ui/startup/startup_browser_creator.cc	2014-08-13 09:56:56.000000000 +0200
@@ -81,7 +81,7 @@
 #include "chromeos/chromeos_switches.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && (defined(OS_LINUX) || defined(OS_FREEBSD))
 #include "ui/events/x/touch_factory_x11.h"
 #endif
 
