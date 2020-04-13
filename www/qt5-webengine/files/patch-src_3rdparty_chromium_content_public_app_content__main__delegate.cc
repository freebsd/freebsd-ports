--- src/3rdparty/chromium/content/public/app/content_main_delegate.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/content/public/app/content_main_delegate.cc
@@ -38,13 +38,13 @@ bool ContentMainDelegate::DelaySandboxInitialization(
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
