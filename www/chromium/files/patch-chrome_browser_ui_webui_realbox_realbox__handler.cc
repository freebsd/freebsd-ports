--- chrome/browser/ui/webui/realbox/realbox_handler.cc.orig	2024-01-30 07:53:34 UTC
+++ chrome/browser/ui/webui/realbox/realbox_handler.cc
@@ -146,7 +146,7 @@ const char* kMacShareIconResourceName =
 #elif BUILDFLAG(IS_WIN)
 const char* kWinShareIconResourceName =
     "//resources/cr_components/omnibox/icons/win_share.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char* kLinuxShareIconResourceName =
     "//resources/cr_components/omnibox/icons/share.svg";
 #else
@@ -203,7 +203,7 @@ static void DefineChromeRefreshRealboxIcons() {
 #elif BUILDFLAG(IS_WIN)
   kWinShareIconResourceName =
       "//resources/cr_components/omnibox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kLinuxShareIconResourceName =
       "//resources/cr_components/omnibox/icons/share_cr23.svg";
 #else
@@ -818,7 +818,7 @@ std::string RealboxHandler::PedalVectorIconToResourceN
       icon.name == omnibox::kShareWinChromeRefreshIcon.name) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == omnibox::kShareIcon.name ||
       icon.name == omnibox::kShareLinuxChromeRefreshIcon.name) {
     return kLinuxShareIconResourceName;
