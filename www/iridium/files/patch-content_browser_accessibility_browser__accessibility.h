--- content/browser/accessibility/browser_accessibility.h.orig	2017-04-19 19:06:33 UTC
+++ content/browser/accessibility/browser_accessibility.h
@@ -40,7 +40,7 @@
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
