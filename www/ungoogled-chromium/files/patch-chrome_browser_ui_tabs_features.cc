--- chrome/browser/ui/tabs/features.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/ui/tabs/features.cc
@@ -16,7 +16,7 @@ BASE_FEATURE(kTabSearchPositionSetting,
 bool CanShowTabSearchPositionSetting() {
 // Mac and other platforms will always have the tab search position in the
 // correct location, cros/linux/win git the user the option to change.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kTabSearchPositionSetting);
 #else
   return false;
