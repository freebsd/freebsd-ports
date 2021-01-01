--- chrome/app/chrome_main.cc.orig	2020-04-10 00:39:09 UTC
+++ chrome/app/chrome_main.cc
@@ -118,11 +118,11 @@ int ChromeMain(int argc, const char** argv) {
   MainThreadStackSamplingProfiler scoped_sampling_profiler;
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if !defined(CHROME_MULTIPLE_DLL_CHILD)
   net::trace_urlreq_cb = &trace_url_request;
