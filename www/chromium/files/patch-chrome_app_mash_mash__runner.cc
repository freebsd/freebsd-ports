--- chrome/app/mash/mash_runner.cc.orig	2017-03-09 20:04:27 UTC
+++ chrome/app/mash/mash_runner.cc
@@ -249,7 +249,7 @@ int MashMain() {
   // TODO(sky): wire this up correctly.
   service_manager::InitializeLogging();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::AtExitManager exit_manager;
 #endif
 
