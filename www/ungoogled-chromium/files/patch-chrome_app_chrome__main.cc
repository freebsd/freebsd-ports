--- chrome/app/chrome_main.cc.orig	2023-05-05 12:12:41 UTC
+++ chrome/app/chrome_main.cc
@@ -28,11 +28,11 @@
 #include "chrome/app/notification_metrics.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/base_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/app/chrome_main_linux.h"
 #endif
 
@@ -147,7 +147,7 @@ int ChromeMain(int argc, const char** argv) {
   SetUpBundleOverrides();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AppendExtraArgumentsToCommandLine(command_line);
 #endif
 
@@ -175,7 +175,7 @@ int ChromeMain(int argc, const char** argv) {
     headless::SetUpCommandLine(command_line);
   } else {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     if (headless::IsOldHeadlessMode()) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       command_line->AppendSwitch(::headless::switches::kEnableCrashReporter);
