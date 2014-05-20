--- ./chrome/browser/web_applications/web_app.cc.orig	2014-04-30 22:42:17.000000000 +0200
+++ ./chrome/browser/web_applications/web_app.cc	2014-05-04 14:38:46.000000000 +0200
@@ -226,7 +226,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   file_util::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
