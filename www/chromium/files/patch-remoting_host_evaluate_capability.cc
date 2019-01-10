--- remoting/host/evaluate_capability.cc.orig	2019-01-09 13:06:32.177219000 +0100
+++ remoting/host/evaluate_capability.cc	2019-01-09 13:06:46.855681000 +0100
@@ -50,7 +50,7 @@
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
