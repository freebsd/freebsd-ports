--- chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.cc
@@ -46,7 +46,7 @@ std::u16string RelaunchChromeBanner::GetTitle() const 
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE_LINUX
 #endif
   );
@@ -56,7 +56,7 @@ std::u16string RelaunchChromeBanner::GetDescription() 
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION_LINUX
 #endif
   );
