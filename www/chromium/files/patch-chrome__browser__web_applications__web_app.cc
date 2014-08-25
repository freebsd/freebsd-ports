--- ./chrome/browser/web_applications/web_app.cc.orig	2014-08-20 21:02:13.000000000 +0200
+++ ./chrome/browser/web_applications/web_app.cc	2014-08-22 15:06:25.000000000 +0200
@@ -441,7 +441,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   file_util::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
