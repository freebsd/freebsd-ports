--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc.orig	2026-02-16 10:45:29 UTC
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc
@@ -959,7 +959,7 @@ std::vector<Suggestion> GetCreditCardSuggestionsForTou
                              /*extracted_amount_in_micros=*/std::nullopt));
     manager.GetCreditCardFormEventLogger().OnBnplSuggestionShown();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     manager.client()
         .GetPersonalDataManager()
         .payments_data_manager()
