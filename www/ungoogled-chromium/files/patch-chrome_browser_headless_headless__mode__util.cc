--- chrome/browser/headless/headless_mode_util.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -9,7 +9,7 @@
 // New headless mode is available on Linux, Windows and Mac platforms.
 // More platforms will be added later, so avoid function level clutter
 // by providing stub implementations at the end of the file.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 #include "base/check_deref.h"
 #include "base/command_line.h"
