--- ui/base/ui_base_features.h.orig	2024-11-04 08:56:03 UTC
+++ ui/base/ui_base_features.h
@@ -141,7 +141,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kWaylandTextInputV3);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
