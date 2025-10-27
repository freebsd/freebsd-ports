--- components/password_manager/core/browser/features/password_features.h.orig	2025-10-21 16:57:35 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -138,7 +138,7 @@ BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable)
 // terminal.
 BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
