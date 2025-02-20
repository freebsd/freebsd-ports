--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-02-20 09:59:21 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -11,7 +11,7 @@ BASE_FEATURE(kAutofillDisableLocalCardMigration,
              "AutofillDisableLocalCardMigration",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 // When enabled, Chrome will extract the checkout amount from the checkout page
 // of the allowlisted merchant websites.
@@ -322,7 +322,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccounts,
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
