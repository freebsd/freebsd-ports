--- tools/gn/args.cc.orig	2016-08-13 15:22:20.957491000 +0300
+++ tools/gn/args.cc	2016-08-13 15:22:40.739449000 +0300
@@ -222,6 +222,8 @@
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_BSD)
+  os = "bsd";
 #elif defined(OS_ANDROID)
   os = "android";
 #else
