--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc
@@ -324,7 +324,7 @@ int HeadlessContentMainDelegate::RunProcess(
 }
 #endif  // !defined(CHROME_MULTIPLE_DLL_CHILD)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -359,7 +359,7 @@ void HeadlessContentMainDelegate::ZygoteForked() {
   breakpad::InitCrashReporter(process_type);
 #endif
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // static
 HeadlessContentMainDelegate* HeadlessContentMainDelegate::GetInstance() {
