--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-11-06 10:11:34 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -185,7 +185,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -216,7 +216,7 @@ void AmountExtractionManager::OnTimeoutReached() {
                                              /*timeout_reached=*/true);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -234,7 +234,7 @@ AmountExtractionManager::CheckEligibilityForFeaturesRe
 
   // Check eligibility of BNPL feature.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (BnplManager::IsEligibleForBnpl(autofill_manager_->client())) {
       eligible_features.insert(EligibleFeature::kBnpl);
     }
