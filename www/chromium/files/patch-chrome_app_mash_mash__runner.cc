--- chrome/app/mash/mash_runner.cc.orig	2017-02-02 02:02:48 UTC
+++ chrome/app/mash/mash_runner.cc
@@ -207,7 +207,7 @@ int MashMain() {
   service_manager::InitializeLogging();
 
   std::unique_ptr<base::MessageLoop> message_loop;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::AtExitManager exit_manager;
 #endif
   if (!IsChild())
