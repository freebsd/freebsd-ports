--- chrome/browser/headless/headless_mode_util.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -18,7 +18,7 @@
 #include "chrome/common/chrome_switches.h"
 #include "content/public/common/content_switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gl/gl_switches.h"               // nogncheck
 #include "ui/ozone/public/ozone_switches.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX)
@@ -81,7 +81,7 @@ class HeadlessModeHandleImpl : public HeadlessModeHand
       command_line->AppendSwitchPath(switches::kUserDataDir, GetUserDataDir());
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Headless mode on Linux relies on ozone/headless platform.
   command_line->AppendSwitchASCII(::switches::kOzonePlatform,
                                   switches::kHeadless);
