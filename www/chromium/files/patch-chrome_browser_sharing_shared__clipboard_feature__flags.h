--- chrome/browser/sharing/shared_clipboard/feature_flags.h.orig	2020-03-16 18:40:29 UTC
+++ chrome/browser/sharing/shared_clipboard/feature_flags.h
@@ -17,14 +17,14 @@ extern const base::Feature kSharedClipboardReceiver;
 // Feature to allow shared clipboard gets processed.
 extern const base::Feature kSharedClipboardUI;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Feature to enable handling remote copy messages.
 extern const base::Feature kRemoteCopyReceiver;
 
 // List of allowed origins to fetch images from, comma separated.
 extern const base::FeatureParam<std::string> kRemoteCopyAllowedOrigins;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #endif  // CHROME_BROWSER_SHARING_SHARED_CLIPBOARD_FEATURE_FLAGS_H_
