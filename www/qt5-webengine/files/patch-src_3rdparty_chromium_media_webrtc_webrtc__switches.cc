--- src/3rdparty/chromium/media/webrtc/webrtc_switches.cc.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/media/webrtc/webrtc_switches.cc
@@ -44,7 +44,7 @@ namespace media {
 
 bool IsWebRtcApmInAudioServiceEnabled() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(features::kWebRtcApmInAudioService) &&
          !base::CommandLine::ForCurrentProcess()->HasSwitch(
              switches::kForceDisableWebRtcApmInAudioService);
@@ -53,4 +53,4 @@ bool IsWebRtcApmInAudioServiceEnabled() {
 #endif
 }
 
-}  // namespace media
\ No newline at end of file
+}  // namespace media
