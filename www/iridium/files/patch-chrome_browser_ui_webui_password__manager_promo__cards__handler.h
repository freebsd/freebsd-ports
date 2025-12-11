--- chrome/browser/ui/webui/password_manager/promo_cards_handler.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.h
@@ -52,7 +52,7 @@ class PromoCardsHandler : public content::WebUIMessage
 
   PasswordPromoCardBase* GetPromoToShowAndUpdatePref();
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnEncryptorReceived(base::Value callback_id,
                            os_crypt_async::Encryptor encryptor);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -60,7 +60,7 @@ class PromoCardsHandler : public content::WebUIMessage
   raw_ptr<Profile, DanglingUntriaged> profile_;
 
   std::vector<std::unique_ptr<PasswordPromoCardBase>> promo_cards_;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This points into `promo_cards_`, so should be ordered after it.
   raw_ptr<RelaunchChromePromo> relaunch_chrome_promo_ = nullptr;
 
