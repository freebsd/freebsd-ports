--- ui/views/accessibility/native_view_accessibility.h.orig	2017-04-19 19:06:54 UTC
+++ ui/views/accessibility/native_view_accessibility.h
@@ -27,7 +27,7 @@
 #define PLATFORM_HAS_NATIVE_VIEW_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_VIEW_ACCESSIBILITY_IMPL 1
 #endif
 
