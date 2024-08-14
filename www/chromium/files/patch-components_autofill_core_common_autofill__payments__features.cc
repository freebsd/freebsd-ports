--- components/autofill/core/common/autofill_payments_features.cc.orig	2024-07-30 11:12:21 UTC
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -248,7 +248,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccounts,
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
