--- components/signin/public/base/signin_switches.h.orig	2024-04-19 13:02:56 UTC
+++ components/signin/public/base/signin_switches.h
@@ -123,7 +123,7 @@ bool IsExplicitBrowserSigninUIOnDesktopEnabled(
 
 // Controls the view mode for (history) sync screen.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kMinorModeRestrictionsForHistorySyncOptIn);
 
