--- chrome/browser/ui/views/app_menu/send_tab_to_self_dynamic_menu.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/views/app_menu/send_tab_to_self_dynamic_menu.cc
@@ -103,7 +103,7 @@ bool SendTabToSelfDynamicMenu::ShouldShowSubmenu() con
       return base::FeatureList::IsEnabled(
           send_tab_to_self::kSendTabToSelfSubmenuSigninPromos);
     case send_tab_to_self::EntryPointDisplayReason::kInformNoTargetDevice:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(
                  send_tab_to_self::kSendTabToSelfSubmenuSigninPromos) &&
              base::FeatureList::IsEnabled(
