--- ui/base/ui_base_features.h.orig	2020-03-03 18:54:06 UTC
+++ ui/base/ui_base_features.h
@@ -65,10 +65,10 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
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
