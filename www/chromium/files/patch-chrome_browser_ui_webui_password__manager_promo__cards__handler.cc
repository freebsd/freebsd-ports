--- chrome/browser/ui/webui/password_manager/promo_cards_handler.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.cc
@@ -31,7 +31,7 @@
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.h"
 #include "components/os_crypt/async/browser/os_crypt_async.h"
@@ -78,7 +78,7 @@ PromoCardsHandler::PromoCardsHandler(Profile* profile)
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto relaunch_promo =
       std::make_unique<RelaunchChromePromo>(profile->GetPrefs());
   relaunch_chrome_promo_ = relaunch_promo.get();
@@ -118,7 +118,7 @@ void PromoCardsHandler::HandleGetAvailablePromoCard(
   CHECK_EQ(1U, args.size());
   const base::Value& callback_id = args[0];
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (relaunch_chrome_promo_ &&
       !relaunch_chrome_promo_->is_encryption_available().has_value()) {
     g_browser_process->os_crypt_async()->GetInstance(
@@ -181,7 +181,7 @@ PasswordPromoCardBase* PromoCardsHandler::GetPromoToSh
   return promo_to_show;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PromoCardsHandler::OnEncryptorReceived(
     base::Value callback_id,
     os_crypt_async::Encryptor encryptor) {
