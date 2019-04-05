--- remoting/host/evaluate_capability.cc.orig	2019-03-11 22:01:01 UTC
+++ remoting/host/evaluate_capability.cc
@@ -50,7 +50,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
