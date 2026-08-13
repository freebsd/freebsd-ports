--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -327,7 +327,7 @@ ChromeAutofillClient::~ChromeAutofillClient() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 ChromeAutofillClient::AtMemoryPromoObserver::AtMemoryPromoObserver(
     ChromeAutofillClient* client)
     : content::WebContentsObserver(client->web_contents()), client_(*client) {}
