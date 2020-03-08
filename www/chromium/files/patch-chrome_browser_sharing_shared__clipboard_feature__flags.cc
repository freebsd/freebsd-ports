--- chrome/browser/sharing/shared_clipboard/feature_flags.cc.orig	2020-03-03 18:53:52 UTC
+++ chrome/browser/sharing/shared_clipboard/feature_flags.cc
@@ -11,7 +11,7 @@ const base::Feature kSharedClipboardUI{"SharedClipboar
                                        base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kRemoteCopyReceiver{"RemoteCopyReceiver",
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
