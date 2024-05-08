--- components/password_manager/core/browser/features/password_features.h.orig	2024-04-23 07:42:17 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -94,7 +94,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 // Enables triggering password suggestions through the context menu.
 BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
