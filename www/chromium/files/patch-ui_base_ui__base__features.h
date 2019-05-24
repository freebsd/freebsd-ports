--- ui/base/ui_base_features.h.orig	2019-04-30 22:23:41 UTC
+++ ui/base/ui_base_features.h
@@ -63,10 +63,10 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kEnableAutomaticUiAdjustmentsForTouch;
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Used to have ash (Chrome OS system UI) run in its own process.
 // TODO(jamescook): Make flag only available in Chrome OS.
