--- components/autofill/core/common/autofill_payments_features.cc.orig	2024-08-26 12:06:38 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -8,7 +8,7 @@
 
 namespace autofill::features {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 // When enabled, Chrome will extract the checkout amount from the checkout page
 // of the allowlisted merchant websites.
@@ -272,7 +272,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccounts,
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
