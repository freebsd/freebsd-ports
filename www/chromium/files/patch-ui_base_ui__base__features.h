--- ui/base/ui_base_features.h.orig	2021-07-19 18:45:43 UTC
+++ ui/base/ui_base_features.h
@@ -77,11 +77,11 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 bool IsDeprecateAltBasedSixPackEnabled();
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 // Used to enable forced colors mode for web content.
