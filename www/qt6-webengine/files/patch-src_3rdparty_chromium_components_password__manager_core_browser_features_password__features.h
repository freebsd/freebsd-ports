--- src/3rdparty/chromium/components/password_manager/core/browser/features/password_features.h.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/features/password_features.h
@@ -94,7 +94,7 @@ BASE_DECLARE_FEATURE(kPasswordManagerEnableSenderServi
 // terminal.
 BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC)
