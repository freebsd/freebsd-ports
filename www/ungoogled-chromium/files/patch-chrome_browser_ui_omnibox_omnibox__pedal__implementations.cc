--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2024-02-25 20:22:18 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2005,7 +2005,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareWinChromeRefreshIcon
              : omnibox::kShareWinIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OmniboxFieldTrial::IsChromeRefreshIconsEnabled() ||
                  OmniboxFieldTrial::IsChromeRefreshActionChipIconsEnabled()
              ? omnibox::kShareLinuxChromeRefreshIcon
