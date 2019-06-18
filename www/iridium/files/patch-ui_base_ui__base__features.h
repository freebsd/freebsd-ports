--- ui/base/ui_base_features.h.orig	2019-03-11 22:01:19 UTC
+++ ui/base/ui_base_features.h
@@ -46,9 +46,9 @@ UI_BASE_EXPORT bool IsUsingWMPointerForTouch();
 UI_BASE_EXPORT extern const base::Feature kEnableAutomaticUiAdjustmentsForTouch;
 #endif  // defined(OS_WIN) || defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 UI_BASE_EXPORT extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Used to have ash (Chrome OS system UI) run in its own process.
 // TODO(jamescook): Make flag only available in Chrome OS.
