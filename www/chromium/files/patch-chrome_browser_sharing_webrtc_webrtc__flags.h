--- chrome/browser/sharing/webrtc/webrtc_flags.h.orig	2020-03-30 09:35:47 UTC
+++ chrome/browser/sharing/webrtc/webrtc_flags.h
@@ -8,14 +8,14 @@
 #include "base/feature_list.h"
 #include "build/build_config.h"
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Feature flag to enable receiving PeerConnection requests.
 extern const base::Feature kSharingPeerConnectionReceiver;
 
 // Feature flag to enable sending SharingMessage using PeerConnection.
 extern const base::Feature kSharingPeerConnectionSender;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #endif  // CHROME_BROWSER_SHARING_WEBRTC_WEBRTC_FLAGS_H_
