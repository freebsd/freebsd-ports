--- ui/base/ui_base_features.h.orig	2020-03-16 18:40:43 UTC
+++ ui/base/ui_base_features.h
@@ -61,10 +61,10 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kEnableAutomaticUiAdjustmentsForTouch;
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Used to enable the new controls UI.
 COMPONENT_EXPORT(UI_BASE_FEATURES)
