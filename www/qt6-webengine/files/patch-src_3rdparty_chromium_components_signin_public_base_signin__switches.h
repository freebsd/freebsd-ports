--- src/3rdparty/chromium/components/signin/public/base/signin_switches.h.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/components/signin/public/base/signin_switches.h
@@ -92,7 +92,7 @@ BASE_DECLARE_FEATURE(kUnoDesktop);
 
 // Controls the view mode for (history) sync screen.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kMinorModeRestrictionsForHistorySyncOptIn);
 #endif
 
