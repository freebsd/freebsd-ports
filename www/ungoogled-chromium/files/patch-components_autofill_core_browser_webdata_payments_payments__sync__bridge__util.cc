--- components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc.orig	2025-10-21 16:57:35 UTC
+++ components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc
@@ -1262,7 +1262,7 @@ bool AreMaskedBankAccountSupported() {
 
 bool IsBnplIssuerSupported() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kAutofillEnableBuyNowPayLaterSyncing);
 #else
