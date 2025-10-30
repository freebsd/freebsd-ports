--- chrome/browser/browser_features.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/browser_features.cc
@@ -70,7 +70,7 @@ BASE_FEATURE(kCertVerificationNetworkTime, base::FEATU
 BASE_FEATURE(kClearUserDataUponProfileDestruction,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables usage of os_crypt_async::SecretPortalKeyProvider.  Once
 // `kSecretPortalKeyProviderUseForEncryption` is enabled, this flag cannot be
 // disabled without losing data.
@@ -85,7 +85,7 @@ BASE_FEATURE(kUseFreedesktopSecretKeyProvider,
 // Destroy profiles when their last browser window is closed, instead of when
 // the browser exits.
 BASE_FEATURE(kDestroyProfileOnBrowserClose,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -204,7 +204,7 @@ BASE_FEATURE(kSandboxExternalProtocolBlocked, base::FE
 BASE_FEATURE(kSandboxExternalProtocolBlockedWarning,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If true, encrypt new data with the key provided by SecretPortalKeyProvider.
 // Otherwise, it will only decrypt existing data.
 BASE_FEATURE(kSecretPortalKeyProviderUseForEncryption,
