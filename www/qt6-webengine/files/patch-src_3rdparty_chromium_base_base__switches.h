--- src/3rdparty/chromium/base/base_switches.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/base_switches.h
@@ -60,7 +60,7 @@ extern const char kForceFieldTrialParams[];
 extern const char kForceFieldTrialParams[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1176772): Remove kEnableCrashpad and IsCrashpadEnabled() when
 // Crashpad is fully enabled on Linux.
 extern const char kEnableCrashpad[];
