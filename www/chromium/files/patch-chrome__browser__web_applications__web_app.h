--- ./chrome/browser/web_applications/web_app.h.orig	2014-08-20 21:02:13.000000000 +0200
+++ ./chrome/browser/web_applications/web_app.h	2014-08-22 15:06:25.000000000 +0200
@@ -193,7 +193,7 @@
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
