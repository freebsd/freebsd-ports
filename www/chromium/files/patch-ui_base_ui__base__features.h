--- ui/base/ui_base_features.h.orig	2020-05-13 18:40:37 UTC
+++ ui/base/ui_base_features.h
@@ -58,10 +58,10 @@ COMPONENT_EXPORT(UI_BASE_FEATURES) extern const base::
 COMPONENT_EXPORT(UI_BASE_FEATURES) bool IsUsingWMPointerForTouch();
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Used to enable forced colors mode for web content.
 COMPONENT_EXPORT(UI_BASE_FEATURES) extern const base::Feature kForcedColors;
