--- src/chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -346,7 +346,7 @@ void ChromeAutofillClient::AtMemoryCopyP
                                            ->GetPrimaryMainFrame()
                                            ->GetPageUkmSourceId())) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     client_->ShowAutofillAtMemoryPromo();
 #endif
   }
@@ -398,7 +398,7 @@ void ChromeAutofillClient::AtMemoryCopyP
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ChromeAutofillClient::ShowAutofillAtMemoryPromo() {
   // TODO(crbug.com/519061643) Double check if we also need to check a field
   // url here.
