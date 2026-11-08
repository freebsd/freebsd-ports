--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc.orig	2026-10-18 13:29:39 UTC
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc
@@ -1351,7 +1351,7 @@ Suggestion CreateCreditCardSuggestion(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Newly-synced cards start with a `use_count()` of 1.
   if (credit_card.card_creation_source() ==
           CreditCard::CardCreationSource::kCreationSourceNonChromePayments &&
