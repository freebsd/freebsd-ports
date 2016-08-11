--- content/browser/accessibility/browser_accessibility.h.orig	2016-05-25 15:01:01.000000000 -0400
+++ content/browser/accessibility/browser_accessibility.h	2016-05-27 10:16:53.216804000 -0400
@@ -38,7 +38,7 @@
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11) && !defined(OS_CHROMEOS)
 #define PLATFORM_HAS_NATIVE_ACCESSIBILITY_IMPL 1
 #endif
 
@@ -50,7 +50,7 @@
 class BrowserAccessibilityManager;
 #if defined(OS_WIN)
 class BrowserAccessibilityWin;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
 class BrowserAccessibilityAuraLinux;
 #endif
 
