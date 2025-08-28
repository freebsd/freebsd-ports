--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2025-08-18 00:53:11 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -165,7 +165,7 @@ BASE_FEATURE(kWaylandTextInputV3,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, users not specify --ozone-platform-hint switch
 // will get --ozone-platform-hint=auto treatment. https://crbug.com/40250220.
 COMPONENT_EXPORT(UI_BASE_FEATURES)
@@ -278,7 +278,7 @@ BASE_FEATURE(kUiCompositorScrollWithLayers,
 
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
 BASE_FEATURE(kExperimentalFlingAnimation,
@@ -389,7 +389,7 @@ bool IsForcedColorsEnabled() {
 // and Linux. This feature will be released for other platforms in later
 // milestones.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_ENABLED_BY_DEFAULT);
 #else
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_DISABLED_BY_DEFAULT);
