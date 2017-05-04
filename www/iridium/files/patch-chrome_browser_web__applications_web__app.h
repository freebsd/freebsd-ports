--- chrome/browser/web_applications/web_app.h.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/web_applications/web_app.h
@@ -208,7 +208,7 @@ typedef std::vector<WebApplicationInfo::
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
