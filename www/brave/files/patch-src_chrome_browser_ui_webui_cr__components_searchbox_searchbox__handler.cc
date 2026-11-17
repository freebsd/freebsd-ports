--- src/chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc
@@ -233,7 +233,7 @@ constexpr char kMacShareIconResourceName
 #elif BUILDFLAG(IS_WIN)
 constexpr char kWinShareIconResourceName[] =
     "//resources/cr_components/searchbox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLinuxShareIconResourceName[] =
     "//resources/cr_components/searchbox/icons/share_cr23.svg";
 #else
@@ -778,7 +778,7 @@ std::string SearchboxHandler::Autocomple
                         : omnibox::kShareWinChromeRefreshOldIcon.name)) {
     resource_name = kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == (features::IsRoundedIconsEnabled()
                         ? omnibox::kSendIcon.name
                         : omnibox::kShareLinuxChromeRefreshOldIcon.name)) {
