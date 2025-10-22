--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-10-21 16:57:35 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -25,7 +25,7 @@ BASE_FEATURE(kAutofillEnableAllowlistForBmoCardCategor
 BASE_FEATURE(kAutofillEnableAmountExtraction,
              "AutofillEnableAmountExtraction",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -51,7 +51,7 @@ BASE_FEATURE(kAutofillEnableAmountExtractionTesting,
 BASE_FEATURE(kAutofillEnableBuyNowPayLater,
              "AutofillEnableBuyNowPayLater",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLaterForKlarna,
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
              "AutofillEnableBuyNowPayLaterSyncing",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -337,7 +337,7 @@ BASE_FEATURE(kDisableAutofillStrikeSystem,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
