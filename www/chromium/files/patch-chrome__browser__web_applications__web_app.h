--- chrome/browser/web_applications/web_app.h.orig	2014-10-10 08:54:11 UTC
+++ chrome/browser/web_applications/web_app.h
@@ -208,7 +208,7 @@
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
