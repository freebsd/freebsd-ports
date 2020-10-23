--- remoting/host/evaluate_capability.cc.orig	2020-09-08 19:14:09 UTC
+++ remoting/host/evaluate_capability.cc
@@ -51,7 +51,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
