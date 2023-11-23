--- src/3rdparty/chromium/base/base_switches.cc.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/base/base_switches.cc
@@ -170,7 +170,7 @@ const char kForceFieldTrialParams[] = "force-fieldtria
 
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1176772): Remove kEnableCrashpad and IsCrashpadEnabled() when
 // Crashpad is fully enabled on Linux. Indicates that Crashpad should be
 // enabled.
