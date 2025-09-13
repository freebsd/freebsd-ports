--- chrome/browser/browser_features.h.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/browser_features.h
@@ -39,7 +39,7 @@ BASE_DECLARE_FEATURE(kCertificateTransparencyAskBefore
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 BASE_DECLARE_FEATURE(kClearUserDataUponProfileDestruction);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProvider);
 #endif
@@ -87,7 +87,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServiceUnsandboxed
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 BASE_DECLARE_FEATURE(kUseFreedesktopSecretKeyProviderForEncryption);
 #endif
