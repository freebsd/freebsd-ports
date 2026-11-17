--- src/components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -175,7 +175,7 @@ using SuggestionDataSource = SuggestionG
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
