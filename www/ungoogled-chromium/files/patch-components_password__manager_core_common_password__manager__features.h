--- components/password_manager/core/common/password_manager_features.h.orig	2023-05-05 12:12:41 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -42,7 +42,7 @@ BASE_DECLARE_FEATURE(kEnablePasswordManagerWithinFence
 BASE_DECLARE_FEATURE(kFillingAcrossAffiliatedWebsites);
 BASE_DECLARE_FEATURE(kFillOnAccountSelect);
 BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kInferConfirmationPasswordField);
@@ -75,7 +75,7 @@ BASE_DECLARE_FEATURE(kRecoverFromNeverSaveAndroid);
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)  // Desktop
 BASE_DECLARE_FEATURE(kRevampedPasswordManagementBubble);
 #endif
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSkipUndecryptablePasswords);
 #endif
 #if BUILDFLAG(IS_ANDROID)
