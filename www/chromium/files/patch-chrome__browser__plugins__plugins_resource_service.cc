--- ./chrome/browser/plugins/plugins_resource_service.cc.orig	2014-08-20 21:02:13.000000000 +0200
+++ ./chrome/browser/plugins/plugins_resource_service.cc	2014-08-22 15:06:25.000000000 +0200
@@ -33,7 +33,7 @@
   std::string filename;
 #if defined(OS_WIN)
   filename = "plugins_win.json";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MACOSX)
   filename = "plugins_mac.json";
