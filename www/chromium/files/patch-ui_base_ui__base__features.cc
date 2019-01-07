--- ui/base/ui_base_features.cc.orig	2018-12-28 17:00:26.368000000 +0100
+++ ui/base/ui_base_features.cc	2018-12-28 17:01:57.144030000 +0100
@@ -115,7 +115,7 @@
     "PrecisionTouchpadScrollPhase", base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -125,7 +125,7 @@
     base::FEATURE_DISABLED_BY_DEFAULT
 #endif
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const base::Feature kMash = {"Mash", base::FEATURE_DISABLED_BY_DEFAULT};
 
