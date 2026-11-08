--- components/password_manager/core/browser/password_autofill_manager.cc.orig	2026-10-22 09:04:01 UTC
+++ components/password_manager/core/browser/password_autofill_manager.cc
@@ -447,7 +447,7 @@ void PasswordAutofillManager::DidAcceptSuggestion(
                          weak_ptr_factory_.GetWeakPtr(), payload);
       if (payload.is_cross_domain) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -498,7 +498,7 @@ void PasswordAutofillManager::DidAcceptSuggestion(
                          weak_ptr_factory_.GetWeakPtr(), *password_credential);
       if (password_credential->is_grouped_affiliation) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -756,7 +756,7 @@ void PasswordAutofillManager::DidNavigateFrame() {
       std::make_unique<PasswordManualFallbackMetricsRecorder>();
 #endif  // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   cross_domain_confirmation_controller_.reset();
 #endif
   wait_for_passkeys_timer_.Stop();
