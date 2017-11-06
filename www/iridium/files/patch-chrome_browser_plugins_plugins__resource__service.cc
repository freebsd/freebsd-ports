--- chrome/browser/plugins/plugins_resource_service.cc.orig	2017-04-24 14:40:27 UTC
+++ chrome/browser/plugins/plugins_resource_service.cc
@@ -31,7 +31,7 @@ GURL GetPluginsServerURL() {
   std::string filename;
 #if defined(OS_WIN)
   filename = "plugins_win.json";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MACOSX)
   filename = "plugins_mac.json";
