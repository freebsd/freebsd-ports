--- ui/base/ui_base_features.cc.orig	2025-04-04 08:52:13 UTC
+++ ui/base/ui_base_features.cc
@@ -119,7 +119,7 @@ BASE_FEATURE(kWaylandLinuxDrmSyncobj,
 // Controls whether support for Wayland's per-surface scaling is enabled.
 BASE_FEATURE(kWaylandPerSurfaceScale,
              "WaylandPerSurfaceScale",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -138,7 +138,7 @@ BASE_FEATURE(kWaylandUiScale,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this feature is enabled, users not specify --ozone-platform-hint switch
 // will get --ozone-platform-hint=auto treatment. https://crbug.com/40250220.
 COMPONENT_EXPORT(UI_BASE_FEATURES)
@@ -220,7 +220,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists,
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -296,7 +296,7 @@ bool IsForcedColorsEnabled() {
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
