--- components/password_manager/core/browser/features/password_features.h.orig	2026-08-13 16:48:13 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -194,7 +194,7 @@ BASE_DECLARE_FEATURE(kPreventAPCOnFederatedLogin);
 // Prevents password manager from showing save/update UI on federated login.
 BASE_DECLARE_FEATURE(kPreventPasswordManagerOnFederatedLogin);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
