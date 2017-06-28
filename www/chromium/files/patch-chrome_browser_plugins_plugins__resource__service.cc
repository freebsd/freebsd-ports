--- chrome/browser/plugins/plugins_resource_service.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/plugins/plugins_resource_service.cc
@@ -59,7 +59,7 @@ GURL GetPluginsServerURL() {
   filename = "plugins_win.json";
 #elif defined(OS_CHROMEOS)
   filename = "plugins_chromeos.json";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MACOSX)
   filename = "plugins_mac.json";
