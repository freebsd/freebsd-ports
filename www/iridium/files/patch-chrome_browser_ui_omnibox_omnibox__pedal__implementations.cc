--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1964,7 +1964,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
