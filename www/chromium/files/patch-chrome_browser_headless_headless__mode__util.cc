--- chrome/browser/headless/headless_mode_util.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -9,7 +9,7 @@
 // Native headless is currently available only on Linux and Windows platforms.
 // More platforms will be added later, so avoid function level clutter by
 // providing stub implementations at the end of the file.
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
 #include <cstdlib>
 #include <vector>
@@ -17,7 +17,7 @@
 #include "base/base_switches.h"
 #include "ui/gfx/switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // defined(OS_LINUX)
 
@@ -51,7 +51,7 @@ void SetUpCommandLine(const base::CommandLine* command
     base::CommandLine::ForCurrentProcess()->AppendSwitch(
         ::switches::kNoErrorDialogs);
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Native headless chrome on Linux relies on ozone/headless platform.
   base::CommandLine::ForCurrentProcess()->AppendSwitchASCII(
       ::switches::kOzonePlatform, switches::kHeadless);
