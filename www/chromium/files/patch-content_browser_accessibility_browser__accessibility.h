--- content/browser/accessibility/browser_accessibility.h.orig	2017-06-05 19:03:06 UTC
+++ content/browser/accessibility/browser_accessibility.h
@@ -42,7 +42,7 @@
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
