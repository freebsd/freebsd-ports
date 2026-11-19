--- components/send_tab_to_self/features.h.orig	2026-11-19 12:25:27 UTC
+++ components/send_tab_to_self/features.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(kSendTabToSelfPropagateNavigation
 BASE_DECLARE_FEATURE(kSendTabToSelfSupportAutoOpenInTabGrid);
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, a QR code promo is shown in the Send Tab to Self
 // bubble on desktop when no target devices are found. Guarded to Windows, Mac,
 // and Linux because it relies on `switches::kCrossDeviceSigninFromDesktopUrl`
