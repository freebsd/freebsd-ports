--- components/send_tab_to_self/features.cc.orig	2026-10-18 13:29:39 UTC
+++ components/send_tab_to_self/features.cc
@@ -49,7 +49,7 @@ BASE_FEATURE(kSendTabToSelfPostSendToast, base::FEATUR
 
 BASE_FEATURE(kSendTabToSelfExtraEntryPoints, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Guarded to Windows, Mac, and Linux because it relies on
 // `switches::kCrossDeviceSigninFromDesktopUrl` in
 // `components/signin/public/base/signin_switches.h`.
