--- chrome/browser/web_applications/web_app.h.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/web_applications/web_app.h
@@ -206,7 +206,7 @@ typedef std::vector<WebApplicationInfo::IconInfo> Icon
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
