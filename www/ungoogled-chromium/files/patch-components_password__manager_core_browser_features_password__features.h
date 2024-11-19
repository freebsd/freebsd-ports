--- components/password_manager/core/browser/features/password_features.h.orig	2024-11-16 12:20:41 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -106,7 +106,7 @@ BASE_DECLARE_FEATURE(kPasswordManualFallbackAvailable)
 // Detects password reuse based on hashed password values.
 BASE_DECLARE_FEATURE(kReuseDetectionBasedOnPasswordHashes);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
