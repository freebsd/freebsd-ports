--- src/3rdparty/chromium/base/base_switches.cc.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/base/base_switches.cc
@@ -172,7 +172,7 @@ const char kPackageVersionName[] = "package-version-na
 const char kPackageVersionCode[] = "package-version-code";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1176772): Remove kEnableCrashpad and IsCrashpadEnabled() when
 // Crashpad is fully enabled on Linux. Indicates that Crashpad should be
 // enabled.
