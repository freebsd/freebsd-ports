--- src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc
@@ -8,7 +8,7 @@ namespace autofill::features {
 
 namespace autofill::features {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 // When enabled, Chrome will extract the checkout amount from the checkout page
 // of the allowlisted merchant websites.
@@ -330,7 +330,7 @@ bool ShouldShowImprovedUserConsentForCreditCardSave() 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
