--- components/password_manager/core/browser/password_autofill_manager.cc.orig	2025-08-07 06:57:29 UTC
+++ components/password_manager/core/browser/password_autofill_manager.cc
@@ -288,7 +288,7 @@ void PasswordAutofillManager::DidAcceptSuggestion(
       }
       if (password_credential->is_grouped_affiliation) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -525,7 +525,7 @@ void PasswordAutofillManager::DidNavigateMainFrame() {
   manual_fallback_metrics_recorder_ =
       std::make_unique<PasswordManualFallbackMetricsRecorder>();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   cross_domain_confirmation_controller_.reset();
 #endif
   wait_for_passkeys_timer_.Stop();
