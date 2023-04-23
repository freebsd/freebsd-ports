--- components/password_manager/core/common/password_manager_features.cc.orig	2023-04-22 17:45:15 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -76,7 +76,7 @@ BASE_FEATURE(kFillOnAccountSelect,
              "fill-on-account-select",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
@@ -197,7 +197,7 @@ BASE_FEATURE(kPasswordStrengthIndicator,
              "PasswordStrengthIndicator",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 BASE_FEATURE(kSkipUndecryptablePasswords,
