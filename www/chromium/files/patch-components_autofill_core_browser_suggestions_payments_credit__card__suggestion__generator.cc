--- components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-09-25 15:26:43 UTC
+++ components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -176,7 +176,7 @@ using SuggestionDataSource = SuggestionGenerator::Sugg
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kAutofillEnableSaveAndFill);
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
