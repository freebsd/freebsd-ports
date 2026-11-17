--- src/components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -786,7 +786,7 @@ BrowserAutofillManager::GetAmountExtract
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
