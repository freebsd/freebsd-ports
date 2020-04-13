--- src/3rdparty/chromium/ui/base/ui_base_features.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/ui/base/ui_base_features.h
@@ -59,10 +59,10 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
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
