--- components/password_manager/core/common/password_manager_features.h.orig	2023-10-21 11:51:27 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -24,7 +24,7 @@ namespace password_manager::features {
 // alongside the definition of their values in the .cc file.
 BASE_DECLARE_FEATURE(kEnableOverwritingPlaceholderUsernames);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kForgotPasswordFormSupport);
@@ -43,7 +43,7 @@ BASE_DECLARE_FEATURE(kPasswordGenerationExperiment);
 #endif
 BASE_DECLARE_FEATURE(kPasswordsImportM2);
 BASE_DECLARE_FEATURE(kRecoverFromNeverSaveAndroid);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSkipUndecryptablePasswords);
 #endif
 #if BUILDFLAG(IS_ANDROID)
