--- components/password_manager/core/common/password_manager_features.h.orig	2022-07-22 17:30:31 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -31,7 +31,7 @@ extern const base::Feature KEnablePasswordGenerationFo
 extern const base::Feature kEnablePasswordManagerWithinFencedFrame;
 extern const base::Feature kFillingAcrossAffiliatedWebsites;
 extern const base::Feature kFillOnAccountSelect;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kForceInitialSyncWhenDecryptionFails;
 #endif
 extern const base::Feature kInferConfirmationPasswordField;
@@ -51,11 +51,11 @@ extern const base::Feature kPasswordsAccountStorageRev
 extern const base::Feature kPasswordScriptsFetching;
 extern const base::Feature kRecoverFromNeverSaveAndroid;
 extern const base::Feature kSecondaryServerFieldPredictions;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSkipUndecryptablePasswords;
 #endif
 extern const base::Feature kSupportForAddPasswordsInSettings;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSyncUndecryptablePasswordsLinux;
 #endif
 #if BUILDFLAG(IS_ANDROID)
