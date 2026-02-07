--- chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc
@@ -161,7 +161,7 @@ const char* kMacShareIconResourceName =
 #elif BUILDFLAG(IS_WIN)
 const char* kWinShareIconResourceName =
     "//resources/cr_components/searchbox/icons/win_share.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char* kLinuxShareIconResourceName =
     "//resources/cr_components/searchbox/icons/share.svg";
 #else
@@ -221,7 +221,7 @@ static void DefineChromeRefreshRealboxIcons() {
 #elif BUILDFLAG(IS_WIN)
   kWinShareIconResourceName =
       "//resources/cr_components/searchbox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kLinuxShareIconResourceName =
       "//resources/cr_components/searchbox/icons/share_cr23.svg";
 #else
@@ -547,7 +547,7 @@ std::string SearchboxHandler::AutocompleteIconToResour
   if (icon.name == omnibox::kShareWinChromeRefreshIcon.name) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == omnibox::kShareLinuxChromeRefreshIcon.name) {
     return kLinuxShareIconResourceName;
   }
