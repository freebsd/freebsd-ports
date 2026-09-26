--- components/password_manager/core/browser/features/password_features.h.orig	2026-09-25 15:26:43 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -208,7 +208,7 @@ BASE_DECLARE_FEATURE(kPreventPasswordManagerOnFederate
 // vault passphrase type.
 BASE_DECLARE_FEATURE(kRecordPasswordReadiness);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
