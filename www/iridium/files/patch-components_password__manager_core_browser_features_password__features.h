--- components/password_manager/core/browser/features/password_features.h.orig	2024-08-01 05:47:53 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -93,7 +93,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 // Enables triggering password suggestions through the context menu.
 BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
