--- content/browser/accessibility/browser_accessibility.h.orig	2017-01-26 00:49:13 UTC
+++ content/browser/accessibility/browser_accessibility.h
@@ -38,7 +38,7 @@
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
