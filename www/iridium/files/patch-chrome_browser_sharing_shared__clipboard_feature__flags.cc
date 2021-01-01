--- chrome/browser/sharing/shared_clipboard/feature_flags.cc.orig	2020-02-07 12:34:27 UTC
+++ chrome/browser/sharing/shared_clipboard/feature_flags.cc
@@ -10,12 +10,12 @@ const base::Feature kSharedClipboardReceiver{"SharedCl
 const base::Feature kSharedClipboardUI{"SharedClipboardUI",
                                        base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const base::Feature kRemoteCopyReceiver{"RemoteCopyReceiver",
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
 const base::FeatureParam<std::string> kRemoteCopyAllowedOrigins = {
     &kRemoteCopyReceiver, "RemoteCopyAllowedOrigins", ""};
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
