--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1995,7 +1995,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareWinChromeRefreshIcon
              : omnibox::kShareWinIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OmniboxFieldTrial::IsChromeRefreshIconsEnabled() ||
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareLinuxChromeRefreshIcon
