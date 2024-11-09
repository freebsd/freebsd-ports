--- chrome/browser/browser_features.h.orig	2024-10-22 08:31:56 UTC
+++ chrome/browser/browser_features.h
@@ -29,7 +29,7 @@ BASE_DECLARE_FEATURE(kCertificateTransparencyAskBefore
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 BASE_DECLARE_FEATURE(kClosedTabCache);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 #endif
 
@@ -143,7 +143,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServiceUnsandboxed
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 #endif
 
