--- chrome/browser/sharing/shared_clipboard/feature_flags.cc.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/sharing/shared_clipboard/feature_flags.cc
@@ -7,7 +7,7 @@
 const base::Feature kSharedClipboardUI{"SharedClipboardUI",
                                        base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const base::Feature kRemoteCopyReceiver{"RemoteCopyReceiver",
                                         base::FEATURE_DISABLED_BY_DEFAULT};
@@ -20,5 +20,5 @@ const base::Feature kRemoteCopyImageNotification{
 
 const base::Feature kRemoteCopyProgressNotification{
     "RemoteCopyProgressNotification", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
