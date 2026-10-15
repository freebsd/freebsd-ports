--- chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -127,7 +127,7 @@ class ChromeAutofillClient : public ContentAutofillCli
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Triggers the AtMemory promo bubble.
   void ShowAutofillAtMemoryPromo();
 #endif
