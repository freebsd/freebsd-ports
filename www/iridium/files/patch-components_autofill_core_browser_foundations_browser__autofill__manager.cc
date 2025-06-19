--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2025-06-19 07:37:57 UTC
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -728,7 +728,7 @@ BrowserAutofillManager::GetCreditCardAccessManager() c
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
