--- ui/ozone/common/features.cc.orig	2024-11-16 12:20:41 UTC
+++ ui/ozone/common/features.cc
@@ -35,7 +35,7 @@ BASE_FEATURE(kWaylandSurfaceSubmissionInPixelCoordinat
 // enabled.
 BASE_FEATURE(kWaylandFractionalScaleV1,
              "WaylandFractionalScaleV1",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -47,7 +47,7 @@ BASE_FEATURE(kWaylandFractionalScaleV1,
 // protocol is supported.
 BASE_FEATURE(kWaylandXdgToplevelDrag,
              "WaylandXdgToplevelDrag",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
