--- components/password_manager/core/browser/password_autofill_manager.cc.orig	2026-01-16 14:21:21 UTC
+++ components/password_manager/core/browser/password_autofill_manager.cc
@@ -401,7 +401,7 @@ void PasswordAutofillManager::DidAcceptSuggestion(
                          weak_ptr_factory_.GetWeakPtr(), *password_credential);
       if (password_credential->is_grouped_affiliation) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -649,7 +649,7 @@ void PasswordAutofillManager::DidNavigateMainFrame() {
   manual_fallback_metrics_recorder_ =
       std::make_unique<PasswordManualFallbackMetricsRecorder>();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   cross_domain_confirmation_controller_.reset();
 #endif
   wait_for_passkeys_timer_.Stop();
