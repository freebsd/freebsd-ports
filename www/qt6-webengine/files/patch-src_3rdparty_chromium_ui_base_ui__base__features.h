--- src/3rdparty/chromium/ui/base/ui_base_features.h.orig	2025-08-18 00:53:11 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.h
@@ -146,7 +146,7 @@ BASE_DECLARE_FEATURE(kWaylandTextInputV3);
 BASE_DECLARE_FEATURE(kWaylandTextInputV3);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
