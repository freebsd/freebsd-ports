--- components/password_manager/core/common/password_manager_features.cc.orig	2022-09-24 10:57:32 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -83,7 +83,7 @@ const base::Feature kFillingAcrossAffiliatedWebsites{
 const base::Feature kFillOnAccountSelect = {"fill-on-account-select",
                                             base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 const base::Feature kForceInitialSyncWhenDecryptionFails = {
@@ -189,14 +189,14 @@ const base::Feature kRecoverFromNeverSaveAndroid = {
 const base::Feature kPasswordStrengthIndicator = {
     "PasswordStrengthIndicator", base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 const base::Feature kSkipUndecryptablePasswords = {
     "SkipUndecryptablePasswords", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, all undecryptable passwords are deleted from the local database
 // during initial sync flow.
 const base::Feature kSyncUndecryptablePasswordsLinux = {
