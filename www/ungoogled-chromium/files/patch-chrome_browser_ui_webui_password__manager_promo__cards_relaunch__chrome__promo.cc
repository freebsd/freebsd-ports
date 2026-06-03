--- chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.cc
@@ -36,7 +36,7 @@ std::u16string RelaunchChromePromo::GetTitle() const {
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE_LINUX
 #endif
   );
@@ -46,7 +46,7 @@ std::u16string RelaunchChromePromo::GetDescription() c
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION_LINUX
 #endif
   );
