--- content/public/app/content_main_delegate.cc.orig	2021-04-14 18:41:03 UTC
+++ content/public/app/content_main_delegate.cc
@@ -24,12 +24,12 @@ int ContentMainDelegate::RunProcess(
   return -1;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 void ContentMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<ZygoteForkDelegate>>* delegates) {}
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 int ContentMainDelegate::TerminateForFatalInitializationError() {
   CHECK(false);
