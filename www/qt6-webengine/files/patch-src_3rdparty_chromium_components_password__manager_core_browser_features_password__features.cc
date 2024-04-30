--- src/3rdparty/chromium/components/password_manager/core/browser/features/password_features.cc.orig	2023-10-27 05:38:38 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/features/password_features.cc
@@ -27,7 +27,7 @@ BASE_FEATURE(kBiometricTouchToFill,
 // Delete undecryptable passwords from the store when Sync is active.
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
