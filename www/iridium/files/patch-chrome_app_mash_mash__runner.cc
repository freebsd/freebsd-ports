--- chrome/app/mash/mash_runner.cc.orig	2017-04-19 19:06:28 UTC
+++ chrome/app/mash/mash_runner.cc
@@ -263,7 +263,7 @@ int MashMain() {
   // TODO(sky): wire this up correctly.
   service_manager::InitializeLogging();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::AtExitManager exit_manager;
 #endif
 
