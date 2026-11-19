--- components/password_manager/core/browser/features/password_features.h.orig	2026-11-19 12:25:27 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -182,7 +182,7 @@ BASE_DECLARE_FEATURE(kPasswordManualFallbackSecurityCh
 BASE_DECLARE_FEATURE(kPasswordSaveInContextErrorResolution);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables resolution of Trusted Vault encryption errors directly within the
 // sign-in autofill dropdown.
 BASE_DECLARE_FEATURE(kPasswordSignInInContextErrorResolution);
@@ -201,7 +201,7 @@ BASE_DECLARE_FEATURE(kPreventPasswordManagerOnFederate
 // vault passphrase type.
 BASE_DECLARE_FEATURE(kRecordPasswordReadiness);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
