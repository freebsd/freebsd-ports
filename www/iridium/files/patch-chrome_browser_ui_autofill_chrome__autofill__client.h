--- chrome/browser/ui/autofill/chrome_autofill_client.h.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.h
@@ -125,7 +125,7 @@ class ChromeAutofillClient : public ContentAutofillCli
   ~ChromeAutofillClient() override;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowAutofillAtMemoryPromo();
 #endif
 
@@ -346,7 +346,7 @@ class ChromeAutofillClient : public ContentAutofillCli
 
  protected:
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   class AtMemoryPromoObserver : public content::WebContentsObserver {
    public:
     explicit AtMemoryPromoObserver(ChromeAutofillClient* client);
@@ -449,7 +449,7 @@ class ChromeAutofillClient : public ContentAutofillCli
   std::unique_ptr<ActorKeyMetricsRecorder> actor_key_metrics_recorder_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   AtMemoryPromoObserver at_memory_promo_observer_{this};
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
