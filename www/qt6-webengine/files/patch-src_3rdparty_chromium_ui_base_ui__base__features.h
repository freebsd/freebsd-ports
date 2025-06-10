--- src/3rdparty/chromium/ui/base/ui_base_features.h.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.h
@@ -143,7 +143,7 @@ BASE_DECLARE_FEATURE(kWaylandTextInputV3);
 BASE_DECLARE_FEATURE(kWaylandTextInputV3);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
