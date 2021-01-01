--- media/webrtc/webrtc_switches.cc.orig	2020-02-03 21:52:48 UTC
+++ media/webrtc/webrtc_switches.cc
@@ -50,7 +50,7 @@ namespace media {
 
 bool IsWebRtcApmInAudioServiceEnabled() {
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(features::kWebRtcApmInAudioService) &&
          !base::CommandLine::ForCurrentProcess()->HasSwitch(
              switches::kForceDisableWebRtcApmInAudioService);
