--- components/password_manager/core/browser/features/password_features.h.orig	2026-07-01 06:24:19 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -198,7 +198,7 @@ BASE_DECLARE_FEATURE(kPreventAPCOnFederatedLogin);
 // This flag is only for the prototype version.
 BASE_DECLARE_FEATURE(kPasswordCheckupPrototype);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
