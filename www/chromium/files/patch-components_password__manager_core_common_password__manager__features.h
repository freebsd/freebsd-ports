--- components/password_manager/core/common/password_manager_features.h.orig	2022-02-28 16:54:41 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -41,11 +41,11 @@ extern const base::Feature kPasswordScriptsFetching;
 extern const base::Feature kRecoverFromNeverSaveAndroid;
 extern const base::Feature kReparseServerPredictionsFollowingFormChange;
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
 extern const base::Feature kTreatNewPasswordHeuristicsAsReliable;
