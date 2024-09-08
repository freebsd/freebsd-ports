--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1976,7 +1976,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
