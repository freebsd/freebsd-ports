--- remoting/host/evaluate_capability.cc.orig	2021-04-14 18:41:08 UTC
+++ remoting/host/evaluate_capability.cc
@@ -55,7 +55,7 @@ base::FilePath BuildHostBinaryPath() {
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (path.BaseName().value() ==
       FILE_PATH_LITERAL("chrome-remote-desktop-host")) {
     return path;
