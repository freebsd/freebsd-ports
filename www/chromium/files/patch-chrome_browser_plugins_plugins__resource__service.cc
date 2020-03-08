--- chrome/browser/plugins/plugins_resource_service.cc.orig	2020-03-03 18:53:01 UTC
+++ chrome/browser/plugins/plugins_resource_service.cc
@@ -62,7 +62,7 @@ GURL GetPluginsServerURL() {
   filename = "plugins_win.json";
 #elif defined(OS_CHROMEOS)
   filename = "plugins_chromeos.json";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MACOSX)
   filename = "plugins_mac.json";
