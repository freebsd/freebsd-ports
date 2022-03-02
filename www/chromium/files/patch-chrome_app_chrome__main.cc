--- chrome/app/chrome_main.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/app/chrome_main.cc
@@ -25,7 +25,7 @@
 #include "chrome/app/notification_metrics.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/base_switches.h"
 #endif
 
@@ -146,7 +146,7 @@ int ChromeMain(int argc, const char** argv) {
     headless::SetUpCommandLine(command_line);
   } else {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     if (command_line->HasSwitch(switches::kHeadless)) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       command_line->AppendSwitch(::headless::switches::kEnableCrashReporter);
