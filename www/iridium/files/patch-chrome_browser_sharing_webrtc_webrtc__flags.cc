--- chrome/browser/sharing/webrtc/webrtc_flags.cc.orig	2020-03-30 09:35:30 UTC
+++ chrome/browser/sharing/webrtc/webrtc_flags.cc
@@ -4,12 +4,12 @@
 
 #include "chrome/browser/sharing/webrtc/webrtc_flags.h"
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 const base::Feature kSharingPeerConnectionReceiver{
     "SharingPeerConnectionReceiver", base::FEATURE_DISABLED_BY_DEFAULT};
 
 const base::Feature kSharingPeerConnectionSender{
     "SharingPeerConnectionSender", base::FEATURE_ENABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
