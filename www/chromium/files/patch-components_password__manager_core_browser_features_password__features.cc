--- components/password_manager/core/browser/features/password_features.cc.orig	2023-12-10 06:10:27 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -8,7 +8,7 @@
 
 namespace password_manager::features {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Enables attaching password manager and autofill internals logs to an Autofill
 // Rater Extension Report.
 BASE_FEATURE(kAttachLogsToAutofillRaterExtensionReport,
@@ -30,7 +30,7 @@ BASE_FEATURE(kBiometricTouchToFill,
 // Delete undecryptable passwords from the store when Sync is active.
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
