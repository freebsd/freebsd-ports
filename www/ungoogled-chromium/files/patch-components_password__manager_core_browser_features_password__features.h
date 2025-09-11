--- components/password_manager/core/browser/features/password_features.h.orig	2025-09-10 13:22:16 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -131,7 +131,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 // Detects password reuse based on hashed password values.
 BASE_DECLARE_FEATURE(kReuseDetectionBasedOnPasswordHashes);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
