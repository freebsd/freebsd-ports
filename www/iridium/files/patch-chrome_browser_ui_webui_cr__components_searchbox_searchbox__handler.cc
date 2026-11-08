--- chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc
@@ -219,7 +219,7 @@ constexpr char kMacShareIconResourceName[] =
 #elif BUILDFLAG(IS_WIN)
 constexpr char kWinShareIconResourceName[] =
     "//resources/cr_components/searchbox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLinuxShareIconResourceName[] =
     "//resources/cr_components/searchbox/icons/share_cr23.svg";
 #else
@@ -740,7 +740,7 @@ std::string SearchboxHandler::AutocompleteIconToResour
                         : omnibox::kShareWinChromeRefreshOldIcon.name)) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == (features::IsRoundedIconsEnabled()
                         ? omnibox::kSendIcon.name
                         : omnibox::kShareLinuxChromeRefreshOldIcon.name)) {
