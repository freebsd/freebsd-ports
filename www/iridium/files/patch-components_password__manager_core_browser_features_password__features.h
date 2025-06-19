--- components/password_manager/core/browser/features/password_features.h.orig	2025-06-19 07:37:57 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -114,7 +114,7 @@ BASE_DECLARE_FEATURE(kPostponeOnLoginSuccessful);
 // Detects password reuse based on hashed password values.
 BASE_DECLARE_FEATURE(kReuseDetectionBasedOnPasswordHashes);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
