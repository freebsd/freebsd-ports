--- components/password_manager/core/common/password_manager_features.cc.orig	2023-03-13 07:33:08 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -69,7 +69,7 @@ BASE_FEATURE(kFillOnAccountSelect,
              "fill-on-account-select",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
@@ -186,7 +186,7 @@ BASE_FEATURE(kPasswordStrengthIndicator,
              "PasswordStrengthIndicator",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 BASE_FEATURE(kSkipUndecryptablePasswords,
