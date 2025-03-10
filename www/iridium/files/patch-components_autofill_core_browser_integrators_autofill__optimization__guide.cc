--- components/autofill/core/browser/integrators/autofill_optimization_guide.cc.orig	2025-02-22 18:06:53 UTC
+++ components/autofill/core/browser/integrators/autofill_optimization_guide.cc
@@ -185,7 +185,7 @@ void AutofillOptimizationGuide::OnDidParseForm(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (has_credit_card_field &&
       !personal_data_manager.payments_data_manager()
            .GetServerCreditCards()
