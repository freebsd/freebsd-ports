--- chrome/app/chrome_main.cc.orig	2021-07-19 18:45:06 UTC
+++ chrome/app/chrome_main.cc
@@ -22,7 +22,7 @@
 #include "chrome/app/chrome_main_mac.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 #include "base/base_switches.h"
 #endif
 
@@ -133,12 +133,12 @@ int ChromeMain(int argc, const char** argv) {
   MainThreadStackSamplingProfiler scoped_sampling_profiler;
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 #if defined(OS_LINUX)
