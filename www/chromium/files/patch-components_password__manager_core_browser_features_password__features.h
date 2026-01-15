--- components/password_manager/core/browser/features/password_features.h.orig	2026-01-14 08:33:23 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -171,7 +171,7 @@ BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable)
 // terminal.
 BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
