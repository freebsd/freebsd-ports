--- chrome/browser/ui/webui/password_manager/promo_cards_handler.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/ui/webui/password_manager/promo_cards/web_password_manager_promo.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.h"
 #include "components/os_crypt/async/browser/os_crypt_async.h"
@@ -74,7 +74,7 @@ PromoCardsHandler::PromoCardsHandler(Profile* profile)
           .get()));
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto relaunch_promo =
       std::make_unique<RelaunchChromePromo>(profile->GetPrefs());
   relaunch_chrome_promo_ = relaunch_promo.get();
@@ -114,7 +114,7 @@ void PromoCardsHandler::HandleGetAvailablePromoCard(
   CHECK_EQ(1U, args.size());
   const base::Value& callback_id = args[0];
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (relaunch_chrome_promo_ &&
       !relaunch_chrome_promo_->is_encryption_available().has_value()) {
     g_browser_process->os_crypt_async()->GetInstance(
@@ -177,7 +177,7 @@ PasswordPromoCardBase* PromoCardsHandler::GetPromoToSh
   return promo_to_show;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PromoCardsHandler::OnEncryptorReceived(
     base::Value callback_id,
     os_crypt_async::Encryptor encryptor) {
