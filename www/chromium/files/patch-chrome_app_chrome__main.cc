--- chrome/app/chrome_main.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/app/chrome_main.cc
@@ -26,7 +26,7 @@
 #include "chrome/app/notification_metrics.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 #include "base/base_switches.h"
 #endif
 
@@ -147,7 +147,7 @@ int ChromeMain(int argc, const char** argv) {
     headless::SetUpCommandLine(command_line);
   } else {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
     if (command_line->HasSwitch(switches::kHeadless)) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       command_line->AppendSwitch(::headless::switches::kEnableCrashReporter);
