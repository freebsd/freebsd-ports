--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2028,7 +2028,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return features::IsRoundedIconsEnabled()
              ? omnibox::kShareWindowsIcon
              : omnibox::kShareWinChromeRefreshOldIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return features::IsRoundedIconsEnabled()
              ? omnibox::kSendIcon
              : omnibox::kShareLinuxChromeRefreshOldIcon;
