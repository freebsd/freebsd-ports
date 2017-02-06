--- chrome/browser/web_applications/web_app.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/web_applications/web_app.cc
@@ -507,7 +507,7 @@ void GetIconsInfo(const WebApplicationIn
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   base::i18n::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
