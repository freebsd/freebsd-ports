--- components/send_tab_to_self/features.h.orig	2026-11-11 14:44:17 UTC
+++ components/send_tab_to_self/features.h
@@ -55,7 +55,7 @@ BASE_DECLARE_FEATURE(kSendTabToSelfPostSendToast);
 // to the Omnibox context menu.
 BASE_DECLARE_FEATURE(kSendTabToSelfExtraEntryPoints);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, a QR code promo is shown in the Send Tab to Self
 // bubble on desktop when no target devices are found. Guarded to Windows, Mac,
 // and Linux because it relies on `switches::kCrossDeviceSigninFromDesktopUrl`
