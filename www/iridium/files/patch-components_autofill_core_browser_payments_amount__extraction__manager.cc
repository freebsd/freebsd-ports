--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-06-19 07:37:57 UTC
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -109,7 +109,7 @@ bool AmountExtractionManager::ShouldTriggerAmountExtra
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -123,7 +123,7 @@ bool AmountExtractionManager::ShouldTriggerAmountExtra
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     return base::FeatureList::IsEnabled(
         ::autofill::features::kAutofillEnableAmountExtractionDesktop);
   } else {
@@ -190,7 +190,7 @@ void AmountExtractionManager::OnCheckoutAmountReceived
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -214,7 +214,7 @@ void AmountExtractionManager::OnTimeoutReached() {
       autofill_metrics::AmountExtractionResult::kTimeout);
   // TODO(crbug.com/378517983): Add BNPL flow action logic here.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
