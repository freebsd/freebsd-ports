--- ui/base/ui_base_features.h.orig	2018-12-28 17:00:21.672100000 +0100
+++ ui/base/ui_base_features.h	2018-12-28 17:01:57.139278000 +0100
@@ -42,9 +42,9 @@
 UI_BASE_EXPORT bool IsUsingWMPointerForTouch();
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 UI_BASE_EXPORT extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Used to have ash (Chrome OS system UI) run in its own process.
 // TODO(jamescook): Make flag only available in Chrome OS.
