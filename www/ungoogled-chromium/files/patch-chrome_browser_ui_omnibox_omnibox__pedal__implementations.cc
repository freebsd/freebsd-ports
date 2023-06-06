--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2023-06-05 19:39:05 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1954,7 +1954,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return OmniboxFieldTrial::IsChromeRefreshIconsEnabled()
              ? omnibox::kShareWinChromeRefreshIcon
              : omnibox::kShareWinIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OmniboxFieldTrial::IsChromeRefreshIconsEnabled()
              ? omnibox::kShareLinuxChromeRefreshIcon
              : omnibox::kShareIcon;
