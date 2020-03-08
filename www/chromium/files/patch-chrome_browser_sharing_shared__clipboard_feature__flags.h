--- chrome/browser/sharing/shared_clipboard/feature_flags.h.orig	2020-03-03 18:53:52 UTC
+++ chrome/browser/sharing/shared_clipboard/feature_flags.h
@@ -18,7 +18,7 @@ extern const base::Feature kSharedClipboardReceiver;
 extern const base::Feature kSharedClipboardUI;
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 // Feature to enable handling remote copy messages.
 extern const base::Feature kRemoteCopyReceiver;
 
