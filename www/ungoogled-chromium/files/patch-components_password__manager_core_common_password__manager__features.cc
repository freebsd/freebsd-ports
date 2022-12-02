--- components/password_manager/core/common/password_manager_features.cc.orig	2022-12-02 17:56:32 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -91,7 +91,7 @@ BASE_FEATURE(kFillOnAccountSelect,
              "fill-on-account-select",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
@@ -222,7 +222,7 @@ BASE_FEATURE(kPasswordStrengthIndicator,
              "PasswordStrengthIndicator",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 BASE_FEATURE(kSkipUndecryptablePasswords,
@@ -230,7 +230,7 @@ BASE_FEATURE(kSkipUndecryptablePasswords,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, all undecryptable passwords are deleted from the local database
 // during initial sync flow.
 BASE_FEATURE(kSyncUndecryptablePasswordsLinux,
