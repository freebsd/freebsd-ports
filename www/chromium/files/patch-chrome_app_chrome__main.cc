--- chrome/app/chrome_main.cc.orig	2021-09-24 04:25:56 UTC
+++ chrome/app/chrome_main.cc
@@ -25,7 +25,7 @@
 #include "chrome/app/notification_metrics.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 #include "base/base_switches.h"
 #endif
 
@@ -145,11 +145,11 @@ int ChromeMain(int argc, const char** argv) {
   if (headless::IsChromeNativeHeadless()) {
     headless::SetUpCommandLine(command_line);
   } else {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     if (command_line->HasSwitch(switches::kHeadless))
       return headless::HeadlessShellMain(params);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
   }
 
