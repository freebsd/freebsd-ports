--- components/password_manager/core/common/password_manager_features.h.orig	2022-08-31 12:19:35 UTC
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
@@ -58,10 +58,10 @@ extern const base::Feature kSecondaryServerFieldPredic
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 extern const base::Feature kEnableBiometricAuthenticationInSettings;
 #endif
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSkipUndecryptablePasswords;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSyncUndecryptablePasswordsLinux;
 #endif
 #if BUILDFLAG(IS_ANDROID)
