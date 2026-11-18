--- components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-11-17 21:17:00 UTC
+++ components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -175,7 +175,7 @@ using SuggestionDataSource = SuggestionGenerator::Sugg
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
   return true;
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
