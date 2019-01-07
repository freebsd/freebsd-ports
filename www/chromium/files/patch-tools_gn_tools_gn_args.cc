--- tools/gn/tools/gn/args.cc.orig	2018-12-15 19:22:28.337753000 +0100
+++ tools/gn/tools/gn/args.cc	2018-12-15 19:22:44.479580000 +0100
@@ -294,6 +294,8 @@
   os = "mac";
 #elif defined(OS_LINUX)
   os = "linux";
+#elif defined(OS_BSD)
+  os = "bsd";
 #elif defined(OS_AIX)
   os = "aix";
 #else
