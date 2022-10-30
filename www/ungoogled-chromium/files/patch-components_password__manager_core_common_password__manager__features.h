--- components/password_manager/core/common/password_manager_features.h.orig	2022-10-29 17:50:56 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -38,7 +38,7 @@ extern const base::Feature KEnablePasswordGenerationFo
 extern const base::Feature kEnablePasswordManagerWithinFencedFrame;
 extern const base::Feature kFillingAcrossAffiliatedWebsites;
 extern const base::Feature kFillOnAccountSelect;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kForceInitialSyncWhenDecryptionFails;
 #endif
 extern const base::Feature kInferConfirmationPasswordField;
@@ -68,10 +68,10 @@ extern const base::Feature kPasswordScriptsFetching;
 extern const base::Feature kPasswordsGrouping;
 extern const base::Feature kPasswordStrengthIndicator;
 extern const base::Feature kRecoverFromNeverSaveAndroid;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSkipUndecryptablePasswords;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSyncUndecryptablePasswordsLinux;
 #endif
 #if BUILDFLAG(IS_ANDROID)
