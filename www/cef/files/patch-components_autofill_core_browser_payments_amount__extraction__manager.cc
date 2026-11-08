--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2026-08-31 10:59:09 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -319,7 +319,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
       .Run(parsed_extracted_amount,
            /*timeout_reached=*/false);
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -389,7 +389,7 @@ void AmountExtractionManager::OnTimeoutReached(
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -414,7 +414,7 @@ void AmountExtractionManager::OnTimeoutReachedWithAi(
   std::move(callback).Run(std::move(result));
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -434,7 +434,7 @@ AmountExtractionManager::CheckEligibilityForFeaturesRe
 
   // Check eligibility of BNPL feature.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (IsEligibleForBnpl(autofill_manager_->client())) {
       eligible_features.insert(EligibleFeature::kBnpl);
     }
