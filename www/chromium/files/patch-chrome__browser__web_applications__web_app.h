--- ./chrome/browser/web_applications/web_app.h.orig	2014-08-12 21:01:47.000000000 +0200
+++ ./chrome/browser/web_applications/web_app.h	2014-08-13 09:56:57.000000000 +0200
@@ -188,7 +188,7 @@
                   IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
