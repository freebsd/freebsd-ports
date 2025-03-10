--- components/autofill/core/browser/integrators/autofill_optimization_guide.cc.orig	2025-03-05 08:14:56 UTC
+++ components/autofill/core/browser/integrators/autofill_optimization_guide.cc
@@ -211,7 +211,7 @@ void AutofillOptimizationGuide::OnDidParseForm(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!server_cards.empty() &&
       base::FeatureList::IsEnabled(
           features::kAutofillEnableAmountExtractionDesktop)) {
