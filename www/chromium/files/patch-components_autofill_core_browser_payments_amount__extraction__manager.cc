--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2026-09-25 15:26:43 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -318,7 +318,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
       .Run(parsed_extracted_amount,
            /*timeout_reached=*/false);
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -388,7 +388,7 @@ void AmountExtractionManager::OnTimeoutReached(
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -413,7 +413,7 @@ void AmountExtractionManager::OnTimeoutReachedWithAi(
   std::move(callback).Run(std::move(result));
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -433,7 +433,7 @@ AmountExtractionManager::CheckEligibilityForFeaturesRe
 
   // Check eligibility of BNPL feature.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (IsEligibleForBnpl(autofill_manager_->client())) {
       eligible_features.insert(EligibleFeature::kBnpl);
     }
