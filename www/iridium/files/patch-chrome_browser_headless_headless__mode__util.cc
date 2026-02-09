--- chrome/browser/headless/headless_mode_util.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -13,7 +13,7 @@
 // New headless mode is available on Linux, Windows and Mac platforms.
 // More platforms will be added later, so avoid function level clutter
 // by providing stub implementations at the end of the file.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 #include "base/base_switches.h"
 #include "base/files/file_path.h"
@@ -25,7 +25,7 @@
 #include "chrome/common/chrome_switches.h"
 #include "content/public/common/content_switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gl/gl_switches.h"               // nogncheck
 #include "ui/ozone/public/ozone_switches.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX)
@@ -94,7 +94,7 @@ class HeadlessModeHandleImpl : public HeadlessModeHand
       command_line->AppendSwitchPath(switches::kUserDataDir, user_data_dir);
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Headless mode on Linux relies on ozone/headless platform.
     command_line->AppendSwitchASCII(::switches::kOzonePlatform,
                                     switches::kHeadless);
