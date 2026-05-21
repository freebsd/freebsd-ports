--- src/3rdparty/chromium/components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -789,7 +789,7 @@ payments::BnplManager* BrowserAutofillManager::GetPaym
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
