--- ui/base/ui_base_features.cc.orig	2020-03-16 18:40:43 UTC
+++ ui/base/ui_base_features.cc
@@ -113,7 +113,7 @@ const base::Feature kEnableAutomaticUiAdjustmentsForTo
     "EnableAutomaticUiAdjustmentsForTouch", base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -123,7 +123,7 @@ const base::Feature kDirectManipulationStylus = {
     base::FEATURE_DISABLED_BY_DEFAULT
 #endif
 };
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Disable the FormControlsRefresh feature for all platforms. See
 // crbug.com/1057669.
