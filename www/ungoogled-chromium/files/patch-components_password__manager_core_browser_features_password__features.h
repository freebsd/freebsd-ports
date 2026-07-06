--- components/password_manager/core/browser/features/password_features.h.orig	2026-06-05 13:45:06 UTC
+++ components/password_manager/core/browser/features/password_features.h
@@ -207,7 +207,7 @@ BASE_DECLARE_FEATURE(kProactivelyDownloadModelForPassw
 // This flag is only for the prototype version.
 BASE_DECLARE_FEATURE(kPasswordCheckupPrototype);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
