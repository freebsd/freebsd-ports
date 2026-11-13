--- chrome/browser/ui/send_tab_to_self/send_tab_to_self_sub_menu_model.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/ui/send_tab_to_self/send_tab_to_self_sub_menu_model.cc
@@ -172,7 +172,7 @@ bool ShouldShowSubmenu(ShareEntryPoint entry_point,
     case EntryPointDisplayReason::kOfferReauth:
       return base::FeatureList::IsEnabled(kSendTabToSelfSubmenuSigninPromos);
     case EntryPointDisplayReason::kInformNoTargetDevice:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(kSendTabToSelfSubmenuSigninPromos) &&
              base::FeatureList::IsEnabled(kSendTabToSelfNoTargetDeviceQrCode);
 #else
