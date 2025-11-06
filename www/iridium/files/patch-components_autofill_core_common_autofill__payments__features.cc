--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-11-06 10:11:34 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -26,7 +26,7 @@ BASE_FEATURE(kAutofillEnableAllowlistForBmoCardCategor
 // of the allowlisted merchant websites.
 BASE_FEATURE(kAutofillEnableAmountExtraction,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -42,7 +42,7 @@ BASE_FEATURE(kAutofillEnableAmountExtractionTesting,
 // When enabled, buy now pay later (BNPL) in Autofill will be offered.
 BASE_FEATURE(kAutofillEnableBuyNowPayLater,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -62,7 +62,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLaterForKlarna,
 // When enabled, buy now pay later (BNPL) data will be synced to Chrome clients.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -86,7 +86,7 @@ BASE_FEATURE(kAutofillEnableCardBenefitsForAmericanExp
 // UI.
 BASE_FEATURE(kAutofillEnableCardBenefitsForBmo,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -151,7 +151,7 @@ BASE_FEATURE(kAutofillEnableFlatRateCardBenefitsBlockl
 // Payments Autofill UI.
 BASE_FEATURE(kAutofillEnableFlatRateCardBenefitsFromCurinos,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -301,7 +301,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccounts, base::FEATU
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
