--- components/autofill/core/browser/integrators/autofill_optimization_guide.cc.orig	2025-04-04 08:52:13 UTC
+++ components/autofill/core/browser/integrators/autofill_optimization_guide.cc
@@ -231,7 +231,7 @@ void AutofillOptimizationGuide::OnDidParseForm(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto bnpl_issuer_allowlist_can_be_loaded =
       [&payments_data_manager](std::string_view issuer_id) {
         return base::Contains(payments_data_manager.GetBnplIssuers(), issuer_id,
