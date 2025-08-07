--- components/password_manager/core/browser/password_form_manager.cc.orig	2025-08-07 06:57:29 UTC
+++ components/password_manager/core/browser/password_form_manager.cc
@@ -66,7 +66,7 @@
 #include "components/webauthn/android/webauthn_cred_man_delegate.h"
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/os_crypt.h"
 #endif
 
@@ -242,7 +242,7 @@ bool ShouldUploadCrowdsourcingVotes(const FormOrDigest
   return false;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ShouldShowKeychainErrorBubble(
     std::optional<PasswordStoreBackendError> backend_error) {
   if (!backend_error.has_value()) {
@@ -916,7 +916,7 @@ void PasswordFormManager::OnFetchCompleted() {
         error.value().type);
   }
 
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ShouldShowKeychainErrorBubble(
           form_fetcher_->GetProfileStoreBackendError())) {
     client_->NotifyKeychainError();
