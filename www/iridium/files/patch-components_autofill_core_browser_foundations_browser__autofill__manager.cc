--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2025-09-11 13:19:19 UTC
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -779,7 +779,7 @@ BrowserAutofillManager::GetAmountExtractionManager() {
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
