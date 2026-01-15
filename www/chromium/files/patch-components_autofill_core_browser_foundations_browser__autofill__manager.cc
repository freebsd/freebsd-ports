--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2026-01-14 08:33:23 UTC
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -837,7 +837,7 @@ BrowserAutofillManager::GetAmountExtractionManager() {
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
