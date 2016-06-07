--- ui/views/accessibility/native_view_accessibility.h.orig	2016-03-25 13:05:04 UTC
+++ ui/views/accessibility/native_view_accessibility.h
@@ -22,7 +22,7 @@
 #define PLATFORM_HAS_NATIVE_VIEW_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_VIEW_ACCESSIBILITY_IMPL 1
 #endif
 
