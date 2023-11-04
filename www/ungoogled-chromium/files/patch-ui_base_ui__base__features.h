--- ui/base/ui_base_features.h.orig	2023-11-04 07:08:51 UTC
+++ ui/base/ui_base_features.h
@@ -287,7 +287,7 @@ ChromeRefresh2023Level GetChromeRefresh2023Level();
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kBubbleMetricsApi);
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES) BASE_DECLARE_FEATURE(kWebUiSystemFont);
 #endif
 
