--- components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc.orig	2026-02-16 10:45:29 UTC
+++ components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc
@@ -1255,7 +1255,7 @@ bool AreMaskedBankAccountSupported() {
 
 bool IsBnplIssuerSupported() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kAutofillEnableBuyNowPayLaterSyncing);
 #else
