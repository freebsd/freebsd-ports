--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2024-11-14 07:57:23 UTC
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -43,7 +43,7 @@ std::u16string GetUsernameFromLabel(const std::u16stri
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Returns the password form corresponding to the `payload` data. In most
 // cases there is only one such form stored, but having more than one or no
 // forms is also possible. If there is more than one form, showing any of them
@@ -281,7 +281,7 @@ void PasswordManualFallbackFlow::DidAcceptSuggestion(
     }
     case autofill::SuggestionType::kViewPasswordDetails: {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       std::optional<password_manager::PasswordForm> credentials =
           GetCorrespondingPasswordForm(
               suggestion.GetPayload<Suggestion::PasswordSuggestionDetails>(),
@@ -418,7 +418,7 @@ void PasswordManualFallbackFlow::EnsureCrossDomainPass
     const Suggestion::PasswordSuggestionDetails& payload,
     base::OnceClosure on_allowed) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (payload.is_cross_domain) {
     cross_domain_confirmation_popup_controller_ =
         password_client_->ShowCrossDomainConfirmationPopup(
