--- chrome/browser/browser_features.h.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/browser_features.h
@@ -40,7 +40,7 @@ BASE_DECLARE_FEATURE(kCertificateTransparencyAskBefore
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 BASE_DECLARE_FEATURE(kClearUserDataUponProfileDestruction);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 #endif
 
@@ -84,7 +84,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServiceUnsandboxed
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 #endif
 
