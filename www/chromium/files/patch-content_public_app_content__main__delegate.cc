--- content/public/app/content_main_delegate.cc.orig	2020-09-08 19:14:05 UTC
+++ content/public/app/content_main_delegate.cc
@@ -24,12 +24,12 @@ int ContentMainDelegate::RunProcess(
   return -1;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 void ContentMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<ZygoteForkDelegate>>* delegates) {}
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 int ContentMainDelegate::TerminateForFatalInitializationError() {
   CHECK(false);
