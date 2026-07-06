--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -315,7 +315,7 @@ ChromeAutofillClient::~ChromeAutofillClient() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 ChromeAutofillClient::AtMemoryPromoObserver::AtMemoryPromoObserver(
     ChromeAutofillClient* client)
     : content::WebContentsObserver(client->web_contents()), client_(*client) {}
