--- chrome/browser/web_applications/web_app.cc.orig	2013-11-16 01:16:28.000000000 +0100
+++ chrome/browser/web_applications/web_app.cc	2013-11-17 21:13:42.000000000 +0100
@@ -228,7 +228,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   file_util::ReplaceIllegalCharactersInPath(&app_name, '_');
   TrimString(app_name, "_", &app_name);
