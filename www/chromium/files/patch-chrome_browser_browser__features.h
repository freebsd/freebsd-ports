--- chrome/browser/browser_features.h.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/browser_features.h
@@ -37,7 +37,7 @@ BASE_DECLARE_FEATURE(kBookmarkTriggerForPrerender2);
 BASE_DECLARE_FEATURE(kCertificateTransparencyAskBeforeEnabling);
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 #endif
 
@@ -102,7 +102,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServiceUnsandboxed
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 #endif
 
