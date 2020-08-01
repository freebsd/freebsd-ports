--- chrome/browser/sharing/shared_clipboard/feature_flags.h.orig	2020-07-07 21:57:32 UTC
+++ chrome/browser/sharing/shared_clipboard/feature_flags.h
@@ -14,7 +14,7 @@
 // Feature to allow shared clipboard gets processed.
 extern const base::Feature kSharedClipboardUI;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Feature to enable handling remote copy messages.
 extern const base::Feature kRemoteCopyReceiver;
@@ -30,7 +30,7 @@ extern const base::Feature kRemoteCopyPersistentNotifi
 
 // Feature to enable progress notifications for remote copy messages.
 extern const base::Feature kRemoteCopyProgressNotification;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #endif  // CHROME_BROWSER_SHARING_SHARED_CLIPBOARD_FEATURE_FLAGS_H_
