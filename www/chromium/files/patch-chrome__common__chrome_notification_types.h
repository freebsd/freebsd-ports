--- chrome/common/chrome_notification_types.h.orig	2012-07-25 23:17:58.000000000 +0300
+++ chrome/common/chrome_notification_types.h	2012-07-25 23:18:37.000000000 +0300
@@ -54,13 +54,13 @@
   // that was closed, no details are expected.
   NOTIFICATION_WINDOW_CLOSED,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux maximize can be an asynchronous operation. This notification
   // indicates that the window has been maximized. The source is
   // a Source<BrowserWindow> containing the BrowserWindow that was maximized.
   // No details are expected.
   NOTIFICATION_BROWSER_WINDOW_MAXIMIZED,
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // Sent when the language (English, French...) for a page has been detected.
   // The details Details<std::string> contain the ISO 639-1 language code and
