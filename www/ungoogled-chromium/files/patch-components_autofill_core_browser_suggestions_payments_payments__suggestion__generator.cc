--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator.cc.orig	2025-12-06 13:30:52 UTC
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator.cc
@@ -1462,7 +1462,7 @@ std::vector<Suggestion> GetCreditCardSuggestionsForTou
                                  .GetBnplIssuers(),
                              /*extracted_amount_in_micros=*/std::nullopt));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     manager.client()
         .GetPersonalDataManager()
         .payments_data_manager()
