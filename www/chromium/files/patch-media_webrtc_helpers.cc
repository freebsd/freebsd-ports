--- media/webrtc/helpers.cc.orig	2024-04-19 13:02:56 UTC
+++ media/webrtc/helpers.cc
@@ -41,14 +41,14 @@ void ConfigAutomaticGainControl(const AudioProcessingS
     return;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool kInputVolumeAdjustmentOverrideAllowed = true;
 #elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
   const bool kInputVolumeAdjustmentOverrideAllowed = false;
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Use AGC2 digital and input volume controller.
   // TODO(crbug.com/1375239): Remove `kWebRtcAllowInputVolumeAdjustment` safely.
   if (kInputVolumeAdjustmentOverrideAllowed &&
