--- chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -124,7 +124,7 @@ class ChromeAutofillClient : public ContentAutofillCli
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowAutofillAtMemoryPromo();
 #endif
 
@@ -414,7 +414,7 @@ class ChromeAutofillClient : public ContentAutofillCli
   std::unique_ptr<ActorKeyMetricsRecorder> actor_key_metrics_recorder_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   class AtMemoryPromoObserver : public content::WebContentsObserver {
    public:
     explicit AtMemoryPromoObserver(ChromeAutofillClient* client);
