--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-08-07 06:57:29 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -177,7 +177,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -200,7 +200,7 @@ void AmountExtractionManager::OnTimeoutReached() {
       autofill_metrics::AmountExtractionResult::kTimeout);
   // TODO(crbug.com/378517983): Add BNPL flow action logic here.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -219,7 +219,7 @@ AmountExtractionManager::CheckEligibilityForFeaturesRe
   // Check eligibility of BNPL feature.
   // Currently, BNPL is only offered for desktop platforms.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (BnplManager* bnpl_manager = autofill_manager_->GetPaymentsBnplManager();
         bnpl_manager && bnpl_manager->IsEligibleForBnpl()) {
       eligible_features.insert(EligibleFeature::kBnpl);
