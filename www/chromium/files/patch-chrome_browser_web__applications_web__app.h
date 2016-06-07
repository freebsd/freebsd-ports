--- chrome/browser/web_applications/web_app.h.orig	2016-05-11 19:02:17 UTC
+++ chrome/browser/web_applications/web_app.h
@@ -227,7 +227,7 @@ typedef std::vector<WebApplicationInfo::
 void GetIconsInfo(const WebApplicationInfo& app_info, IconInfoList* icons);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Windows that correspond to web apps need to have a deterministic (and
 // different) WMClass than normal chrome windows so the window manager groups
 // them as a separate application.
