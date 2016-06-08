--- chrome/browser/web_applications/web_app.cc.orig	2016-05-11 19:02:17 UTC
+++ chrome/browser/web_applications/web_app.cc
@@ -514,7 +514,7 @@ void GetIconsInfo(const WebApplicationIn
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   base::i18n::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
