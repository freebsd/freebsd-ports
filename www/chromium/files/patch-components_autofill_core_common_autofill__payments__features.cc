--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-04-04 08:52:13 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -269,7 +269,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccounts,
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
