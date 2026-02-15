--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-02-15 10:01:45 UTC
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -197,7 +197,7 @@ void BnplManager::OnSuggestionsShown(
     base::span<const Suggestion> suggestions,
     UpdateSuggestionsCallback update_suggestions_callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (base::Contains(suggestions, SuggestionType::kBnplEntry,
                      &Suggestion::type) &&
       base::FeatureList::IsEnabled(
@@ -816,7 +816,7 @@ void BnplManager::MaybeUpdateDesktopSuggestionsWithBnp
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
