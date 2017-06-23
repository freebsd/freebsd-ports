--- content/browser/accessibility/browser_accessibility_manager.h.orig	2017-06-05 19:03:06 UTC
+++ content/browser/accessibility/browser_accessibility_manager.h
@@ -36,7 +36,7 @@ class BrowserAccessibilityManager;
 class BrowserAccessibilityManagerAndroid;
 #elif defined(OS_WIN)
 class BrowserAccessibilityManagerWin;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
 class BrowserAccessibilityManagerAuraLinux;
 #elif defined(OS_MACOSX)
 class BrowserAccessibilityManagerMac;
@@ -251,7 +251,7 @@ class CONTENT_EXPORT BrowserAccessibilityManager : pub
   BrowserAccessibilityManagerAndroid* ToBrowserAccessibilityManagerAndroid();
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(USE_X11)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(USE_X11)
   BrowserAccessibilityManagerAuraLinux*
       ToBrowserAccessibilityManagerAuraLinux();
 #endif
