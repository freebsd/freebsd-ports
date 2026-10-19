--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -334,7 +334,7 @@ void ChromeAutofillClient::AtMemoryCopyPasteObserver::
                                            ->GetPrimaryMainFrame()
                                            ->GetPageUkmSourceId())) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     client_->ShowAutofillAtMemoryPromo();
 #endif
   }
@@ -386,7 +386,7 @@ void ChromeAutofillClient::AtMemoryCopyPasteObserver::
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChromeAutofillClient::ShowAutofillAtMemoryPromo() {
   // TODO(crbug.com/519061643) Double check if we also need to check a field
   // url here.
