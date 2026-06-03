--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2026-05-09 18:09:27 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -284,7 +284,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
                                              /*timeout_reached=*/false);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -372,7 +372,7 @@ void AmountExtractionManager::OnTimeoutReached() {
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -392,7 +392,7 @@ AmountExtractionManager::CheckEligibilityForFeaturesRe
 
   // Check eligibility of BNPL feature.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (IsEligibleForBnpl(autofill_manager_->client())) {
       eligible_features.insert(EligibleFeature::kBnpl);
     }
