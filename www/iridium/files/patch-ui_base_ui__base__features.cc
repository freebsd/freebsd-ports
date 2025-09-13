--- ui/base/ui_base_features.cc.orig	2025-09-11 13:19:19 UTC
+++ ui/base/ui_base_features.cc
@@ -113,7 +113,7 @@ BASE_FEATURE(kWaylandLinuxDrmSyncobj,
 // Controls whether support for Wayland's per-surface scaling is enabled.
 BASE_FEATURE(kWaylandPerSurfaceScale,
              "WaylandPerSurfaceScale",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -195,7 +195,7 @@ BASE_FEATURE(kUiCompositorUsesLayerLists,
 // native apps on Windows.
 BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -293,7 +293,7 @@ bool IsForcedColorsEnabled() {
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
