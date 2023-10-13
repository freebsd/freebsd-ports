--- components/password_manager/core/common/password_manager_features.cc.orig	2023-10-13 13:20:35 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -18,7 +18,7 @@ BASE_FEATURE(kEnableOverwritingPlaceholderUsernames,
              "EnableOverwritingPlaceholderUsernames",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
@@ -99,7 +99,7 @@ BASE_FEATURE(kRecoverFromNeverSaveAndroid,
              "RecoverFromNeverSaveAndroid_LAUNCHED",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 BASE_FEATURE(kSkipUndecryptablePasswords,
