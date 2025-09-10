--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2025-09-10 13:22:16 UTC
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -46,7 +46,7 @@ std::u16string GetUsernameFromLabel(const std::u16stri
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Returns the password form corresponding to the `payload` data. In most
 // cases there is only one such form stored, but having more than one or no
 // forms is also possible. If there is more than one form, showing any of them
@@ -300,7 +300,7 @@ void PasswordManualFallbackFlow::DidAcceptSuggestion(
     }
     case autofill::SuggestionType::kViewPasswordDetails: {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       std::optional<password_manager::PasswordForm> credentials =
           GetCorrespondingPasswordForm(
               suggestion.GetPayload<Suggestion::PasswordSuggestionDetails>(),
@@ -436,7 +436,7 @@ void PasswordManualFallbackFlow::EnsureCrossDomainPass
     const Suggestion::PasswordSuggestionDetails& payload,
     base::OnceClosure on_allowed) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (payload.is_cross_domain) {
     CHECK(payload.display_signon_realm);
     cross_domain_confirmation_popup_controller_ =
