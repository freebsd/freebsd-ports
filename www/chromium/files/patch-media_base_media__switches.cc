--- media/base/media_switches.cc.orig	2026-11-19 12:25:27 UTC
+++ media/base/media_switches.cc
@@ -21,7 +21,7 @@
 #include "ui/gl/gl_features.h"
 #include "ui/gl/gl_utils.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "components/system_media_controls/linux/buildflags/buildflags.h"
 #endif
@@ -673,7 +673,7 @@ BASE_FEATURE(kH264SkipUnspecifiedNalus,
 BASE_FEATURE(kHardwareMediaKeyHandling,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_MPRIS)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1143,7 +1143,7 @@ BASE_FEATURE(kFileDialogsTuckPictureInPicture,
 
 // If enabled, users can request Media Remoting without fullscreen-in-tab.
 BASE_FEATURE(kMediaRemotingWithoutFullscreen,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1480,7 +1480,7 @@ BASE_FEATURE(kShowForceRespectUiGainsToggle, base::FEA
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Reduces the number of buffers needed in the output video frame pool to
 // populate the Renderer pipeline for hardware accelerated VideoDecoder in
 // non-low latency scenarios.
@@ -1507,7 +1507,7 @@ BASE_FEATURE(kFuchsiaMediacodecVideoEncoder, base::FEA
 
 #endif  // BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi/v4l2 video decoding on linux. This is already enabled by default
 // on chromeos, but needs an experiment on linux.
 BASE_FEATURE(kAcceleratedVideoDecodeLinux,
@@ -1538,6 +1538,27 @@ BASE_FEATURE(kPulseaudioLoopbackForScreenShare,
 // implementations.
 BASE_FEATURE(kVaapiIgnoreDriverChecks, base::FEATURE_DISABLED_BY_DEFAULT);
 
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
 
 #if BUILDFLAG(IS_MAC)
@@ -1991,7 +2012,7 @@ bool IsSystemLoopbackCaptureSupported() {
 #elif BUILDFLAG(IS_MAC)
   return (IsMacSckSystemLoopbackCaptureSupported() ||
           IsMacCatapSystemLoopbackCaptureSupported());
-#elif BUILDFLAG(IS_LINUX) && defined(USE_PULSEAUDIO)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_PULSEAUDIO)
   return true;
 #else
   return false;
