--- ui/base/ui_base_features.cc.orig	2021-01-18 21:29:48 UTC
+++ ui/base/ui_base_features.cc
@@ -109,7 +109,7 @@ const base::Feature kCompositorThreadedScrollbarScroll
 const base::Feature kExperimentalFlingAnimation {
   "ExperimentalFlingAnimation",
 #if defined(OS_WIN) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -141,7 +141,7 @@ const base::Feature kPrecisionTouchpadLogging{
     "PrecisionTouchpadLogging", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
@@ -152,7 +152,7 @@ const base::Feature kDirectManipulationStylus = {
     base::FEATURE_DISABLED_BY_DEFAULT
 #endif
 };
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 // Enables forced colors mode for web content.
@@ -198,7 +198,7 @@ bool IsCSSColorSchemeUARenderingEnabled() {
 // crbug.com/1012106 for the Windows launch bug, and crbug.com/1012108 for the
 // Mac launch bug.
 const base::Feature kFormControlsRefresh = {"FormControlsRefresh",
-#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_APPLE)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
