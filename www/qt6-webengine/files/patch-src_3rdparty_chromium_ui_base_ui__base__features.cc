--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2025-10-02 00:36:39 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -133,7 +133,7 @@ BASE_FEATURE(kWaylandUiScale,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, users not specify --ozone-platform-hint switch
 // will get --ozone-platform-hint=auto treatment. https://crbug.com/40250220.
 COMPONENT_EXPORT(UI_BASE_FEATURES)
@@ -228,7 +228,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists,
 
 // Enables the use of a touch fling curve that is based on the behavior of
 // native apps on Windows.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -311,7 +311,7 @@ bool IsForcedColorsEnabled() {
 // and Linux. This feature will be released for other platforms in later
 // milestones.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_ENABLED_BY_DEFAULT);
 #else
 BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_DISABLED_BY_DEFAULT);
