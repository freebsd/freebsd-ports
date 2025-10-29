--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-10-28 14:29:43 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -172,7 +172,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -203,7 +203,7 @@ void AmountExtractionManager::OnTimeoutReached() {
                                              /*timeout_reached=*/true);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -221,7 +221,7 @@ AmountExtractionManager::CheckEligibilityForFeaturesRe
 
   // Check eligibility of BNPL feature.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (BnplManager* bnpl_manager = autofill_manager_->GetPaymentsBnplManager();
         bnpl_manager && bnpl_manager->IsEligibleForBnpl()) {
       eligible_features.insert(EligibleFeature::kBnpl);
