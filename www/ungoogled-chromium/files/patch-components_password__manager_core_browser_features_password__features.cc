--- components/password_manager/core/browser/features/password_features.cc.orig	2024-02-03 15:42:55 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -22,7 +22,7 @@ BASE_FEATURE(kBiometricTouchToFill,
 // Delete undecryptable passwords from the store when Sync is active.
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
