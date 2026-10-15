--- chrome/browser/ui/webui/password_manager/notification_cards_handler.h.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/password_manager/notification_cards_handler.h
@@ -55,7 +55,7 @@ class NotificationCardsHandler : public content::WebUI
 
   PasswordNotificationCardBase* GetNotificationCardToShowAndUpdatePref();
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnEncryptorReceived(base::Value callback_id,
                            scoped_refptr<os_crypt_async::Encryptor> encryptor);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -64,7 +64,7 @@ class NotificationCardsHandler : public content::WebUI
 
   std::vector<std::unique_ptr<PasswordNotificationCardBase>>
       notification_cards_;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This points into `notification_cards_`, so should be ordered after it.
   raw_ptr<RelaunchChromeBanner> relaunch_chrome_banner_ = nullptr;
 
