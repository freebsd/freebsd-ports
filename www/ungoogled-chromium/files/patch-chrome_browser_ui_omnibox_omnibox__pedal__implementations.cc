--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2009,7 +2009,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return features::IsRoundedIconsEnabled()
              ? omnibox::kShareWindowsIcon
              : omnibox::kShareWinChromeRefreshOldIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return features::IsRoundedIconsEnabled()
              ? omnibox::kSendIcon
              : omnibox::kShareLinuxChromeRefreshOldIcon;
