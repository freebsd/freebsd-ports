--- src/3rdparty/chromium/ui/base/ui_base_features.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.cc
@@ -120,7 +120,7 @@ const base::Feature kPrecisionTouchpadScrollPhase{
     "PrecisionTouchpadScrollPhase", base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -130,7 +130,7 @@ const base::Feature kDirectManipulationStylus = {
     base::FEATURE_DISABLED_BY_DEFAULT
 #endif
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const base::Feature kMash = {"Mash", base::FEATURE_DISABLED_BY_DEFAULT};
 
