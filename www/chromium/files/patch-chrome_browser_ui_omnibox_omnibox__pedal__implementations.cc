--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2002,7 +2002,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
