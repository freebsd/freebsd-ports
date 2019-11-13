--- chrome/browser/sharing/click_to_call/feature.h.orig	2019-10-21 19:06:23 UTC
+++ chrome/browser/sharing/click_to_call/feature.h
@@ -13,7 +13,7 @@
 extern const base::Feature kClickToCallReceiver;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Feature to allow click to call gets processed on desktop.
 extern const base::Feature kClickToCallUI;
@@ -21,7 +21,7 @@ extern const base::Feature kClickToCallUI;
 // Feature to show click to call in context menu when selected text is a phone
 // number.
 extern const base::Feature kClickToCallContextMenuForSelectedText;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #endif  // CHROME_BROWSER_SHARING_CLICK_TO_CALL_FEATURE_H_
