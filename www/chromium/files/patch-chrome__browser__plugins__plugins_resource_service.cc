--- chrome/browser/plugins/plugins_resource_service.cc.orig	2013-01-03 16:15:04.489512557 +0200
+++ chrome/browser/plugins/plugins_resource_service.cc	2013-01-03 16:16:48.346512702 +0200
@@ -31,7 +31,7 @@
   std::string filename;
 #if defined(OS_WIN)
   filename = "plugins_win.json";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MACOSX)
   filename = "plugins_mac.json";
