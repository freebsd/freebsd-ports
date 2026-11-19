--- components/send_tab_to_self/features.cc.orig	2026-11-19 12:25:27 UTC
+++ components/send_tab_to_self/features.cc
@@ -29,7 +29,7 @@ BASE_FEATURE(kSendTabToSelfSupportAutoOpenInTabGrid,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Guarded to Windows, Mac, and Linux because it relies on
 // `switches::kCrossDeviceSigninFromDesktopUrl` in
 // `components/signin/public/base/signin_switches.h`.
