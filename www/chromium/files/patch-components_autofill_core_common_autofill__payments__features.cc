--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-07-02 06:08:04 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -326,7 +326,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccounts,
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
