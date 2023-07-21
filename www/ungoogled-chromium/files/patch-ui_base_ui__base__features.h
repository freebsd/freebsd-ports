--- ui/base/ui_base_features.h.orig	2023-07-21 09:49:17 UTC
+++ ui/base/ui_base_features.h
@@ -242,7 +242,7 @@ enum class ChromeRefresh2023Level {
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 ChromeRefresh2023Level GetChromeRefresh2023Level();
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES) BASE_DECLARE_FEATURE(kWebUiSystemFont);
 #endif
 
