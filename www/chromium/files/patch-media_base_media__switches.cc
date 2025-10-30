--- media/base/media_switches.cc.orig	2025-10-30 15:44:36 UTC
+++ media/base/media_switches.cc
@@ -19,7 +19,7 @@
 #include "ui/gl/gl_features.h"
 #include "ui/gl/gl_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -368,13 +368,35 @@ BASE_FEATURE(kMacCatapLoopbackAudioForScreenShare,
 BASE_FEATURE(kUseSCContentSharingPicker, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables system audio mirroring using pulseaudio.
 BASE_FEATURE(kPulseaudioLoopbackForCast, base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables system audio sharing using pulseaudio.
 BASE_FEATURE(kPulseaudioLoopbackForScreenShare,
              base::FEATURE_DISABLED_BY_DEFAULT);
+
+BASE_FEATURE(kAudioBackend,
+             "AudioBackend",
+             base::FEATURE_ENABLED_BY_DEFAULT);
+
+constexpr base::FeatureParam<AudioBackend>::Option
+    kAudioBackendOptions[] = {
+        {AudioBackend::kAuto,
+         "auto"},
+        {AudioBackend::kPulseAudio, "pulseaudio"},
+        {AudioBackend::kSndio, "sndio"},
+        {AudioBackend::kAlsa, "alsa"}};
+
+const base::FeatureParam<AudioBackend>
+    kAudioBackendParam{
+        &kAudioBackend, "audio-backend",
+#if BUILDFLAG(IS_OPENBSD)
+        AudioBackend::kSndio,
+#elif BUILDFLAG(IS_FREEBSD)
+        AudioBackend::kAuto,
+#endif
+        &kAudioBackendOptions};
 #endif  // BUILDFLAG(IS_LINUX)
 
 // When enabled, MediaCapabilities will check with GPU Video Accelerator
@@ -626,7 +648,7 @@ BASE_FEATURE(kFileDialogsTuckPictureInPicture,
 
 // Show toolbar button that opens dialog for controlling media sessions.
 BASE_FEATURE(kGlobalMediaControls,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -644,7 +666,7 @@ BASE_FEATURE(kGlobalMediaControlsUpdatedUI, base::FEAT
 #if !BUILDFLAG(IS_ANDROID)
 // If enabled, users can request Media Remoting without fullscreen-in-tab.
 BASE_FEATURE(kMediaRemotingWithoutFullscreen,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -655,7 +677,7 @@ BASE_FEATURE(kMediaRemotingWithoutFullscreen,
 // Show picture-in-picture button in Global Media Controls.
 BASE_FEATURE(kGlobalMediaControlsPictureInPicture,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -677,7 +699,7 @@ BASE_FEATURE(kSuspendMediaForFrozenFrames, base::FEATU
 // autoplay policy.
 BASE_FEATURE(kUnifiedAutoplay, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi/v4l2 video decoding on linux. This is already enabled by default
 // on chromeos, but needs an experiment on linux.
 BASE_FEATURE(kAcceleratedVideoDecodeLinux,
@@ -733,7 +755,7 @@ BASE_FEATURE(kVaapiVp9SModeHWEncoding, base::FEATURE_E
 // Enables VSync aligned MJPEG decoding.
 BASE_FEATURE(kVSyncMjpegDecoding, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable H264 temporal layer encoding with V4L2 HW encoder on ChromeOS.
 BASE_FEATURE(kV4L2H264TemporalLayerHWEncoding,
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1235,7 +1257,7 @@ BASE_FEATURE(kUseOutOfProcessVideoDecoding,
 );
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawn utility processes to perform hardware encode acceleration instead of
 // using the GPU process.
 BASE_FEATURE(kUseOutOfProcessVideoEncoding, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1297,7 +1319,7 @@ BASE_FEATURE(kRecordMediaEngagementScores, base::FEATU
 // Enables Media Engagement Index recording for Web Audio playbacks.
 BASE_FEATURE(kRecordWebAudioEngagement, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Reduces the number of buffers needed in the output video frame pool to
 // populate the Renderer pipeline for hardware accelerated VideoDecoder in
 // non-low latency scenarios.
@@ -1565,7 +1587,7 @@ bool IsSystemLoopbackCaptureSupported() {
 #elif BUILDFLAG(IS_MAC)
   return (IsMacSckSystemLoopbackCaptureSupported() ||
           IsMacCatapSystemLoopbackCaptureSupported());
-#elif BUILDFLAG(IS_LINUX) && defined(USE_PULSEAUDIO)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_PULSEAUDIO)
   return true;
 #else
   return false;
