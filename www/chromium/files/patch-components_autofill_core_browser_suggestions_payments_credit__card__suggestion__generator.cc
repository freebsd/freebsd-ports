--- components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-11-19 12:25:27 UTC
+++ components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -176,7 +176,7 @@ using SuggestionDataSource = SuggestionGenerator::Sugg
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
   return true;
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
