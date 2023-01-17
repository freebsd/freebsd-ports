--- chrome/browser/headless/headless_mode_util.cc.orig	2023-01-17 19:19:00 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -10,11 +10,11 @@
 // New headless mode is available on Linux, Windows and Mac platforms.
 // More platforms will be added later, so avoid function level clutter
 // by providing stub implementations at the end of the file.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 #include "base/base_switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gl/gl_switches.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -64,7 +64,7 @@ void SetUpCommandLine(const base::CommandLine* command
     base::CommandLine::ForCurrentProcess()->AppendSwitch(
         ::switches::kNoErrorDialogs);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Headless mode on Linux relies on ozone/headless platform.
   base::CommandLine::ForCurrentProcess()->AppendSwitchASCII(
       ::switches::kOzonePlatform, switches::kHeadless);
