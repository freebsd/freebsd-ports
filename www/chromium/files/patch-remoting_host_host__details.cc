--- remoting/host/host_details.cc.orig	2017-08-03 00:05:16.000000000 +0200
+++ remoting/host/host_details.cc	2017-08-10 16:20:00.950699000 +0200
@@ -22,7 +22,7 @@
   return "Mac";
 #elif defined(OS_CHROMEOS)
   return "ChromeOS";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return "Linux";
 #elif defined(OS_ANDROID)
   return "Android";
