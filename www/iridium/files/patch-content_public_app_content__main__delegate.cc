--- content/public/app/content_main_delegate.cc.orig	2020-03-16 18:40:32 UTC
+++ content/public/app/content_main_delegate.cc
@@ -39,13 +39,13 @@ bool ContentMainDelegate::DelaySandboxInitialization(
   return false;
 }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 
 void ContentMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<service_manager::ZygoteForkDelegate>>*
         delegates) {}
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 int ContentMainDelegate::TerminateForFatalInitializationError() {
   CHECK(false);
