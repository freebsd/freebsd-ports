--- chrome/app/mash/mash_runner.cc.orig	2017-06-05 19:03:01 UTC
+++ chrome/app/mash/mash_runner.cc
@@ -302,7 +302,7 @@ int MashMain() {
   // TODO(sky): wire this up correctly.
   service_manager::InitializeLogging();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::AtExitManager exit_manager;
 #endif
 
