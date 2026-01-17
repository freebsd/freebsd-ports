--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2003,7 +2003,7 @@ const gfx::VectorIcon& GetSharingHubVectorIcon() {
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
