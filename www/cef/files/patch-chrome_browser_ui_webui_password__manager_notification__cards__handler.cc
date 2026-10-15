--- chrome/browser/ui/webui/password_manager/notification_cards_handler.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/password_manager/notification_cards_handler.cc
@@ -30,7 +30,7 @@
 #endif
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/scoped_refptr.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.h"
@@ -80,7 +80,7 @@ NotificationCardsHandler::NotificationCardsHandler(Pro
 #endif
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto relaunch_banner =
       std::make_unique<RelaunchChromeBanner>(profile->GetPrefs());
   relaunch_chrome_banner_ = relaunch_banner.get();
@@ -124,7 +124,7 @@ void NotificationCardsHandler::HandleGetAvailableNotif
   CHECK_EQ(1U, args.size());
   const base::Value& callback_id = args[0];
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (relaunch_chrome_banner_ &&
       !relaunch_chrome_banner_->is_encryption_available().has_value()) {
     g_browser_process->os_crypt_async()->GetInstance(
@@ -191,7 +191,7 @@ NotificationCardsHandler::GetNotificationCardToShowAnd
   return card_to_show;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NotificationCardsHandler::OnEncryptorReceived(
     base::Value callback_id,
     scoped_refptr<os_crypt_async::Encryptor> encryptor) {
