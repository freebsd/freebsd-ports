--- chrome/browser/web_applications/web_app.h.orig	2013-11-08 07:40:41.000000000 +0100
+++ chrome/browser/web_applications/web_app.h	2013-11-15 23:02:30.000000000 +0100
@@ -97,7 +97,7 @@
                   IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
