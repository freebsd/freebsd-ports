--- src/chrome/browser/browser_features.cc.orig	2026-09-25 15:26:43 UTC
+++ src/chrome/browser/browser_features.cc
@@ -58,7 +58,7 @@
 BASE_FEATURE(kClearUserDataUponProfileDestruction,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables usage of os_crypt_async::SecretPortalKeyProvider.  Once
 // `kSecretPortalKeyProviderUseForEncryption` is enabled, this flag cannot be
 // disabled without losing data.
@@ -149,7 +149,7 @@
 BASE_FEATURE(kSandboxExternalProtocolBlockedWarning,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If true, encrypt new data with the key provided by SecretPortalKeyProvider.
 // Otherwise, it will only decrypt existing data.
 BASE_FEATURE(kSecretPortalKeyProviderUseForEncryption,
