--- media/base/media_switches.h.orig	2026-09-25 15:26:43 UTC
+++ media/base/media_switches.h
@@ -446,7 +446,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kIgnoreUiGains);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kShowForceRespectUiGainsToggle);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kReduceHardwareVideoDecoderBuffers);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2H264TemporalLayerHWEncoding);
@@ -457,7 +457,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kFuchsiaCdmStoragePa
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kFuchsiaMediacodecVideoEncoder);
 #endif  // BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kAcceleratedVideoEncodeLinux);
@@ -468,6 +468,18 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreferV4L2VideoAcce
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForCast);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForScreenShare);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiIgnoreDriverChecks);
+
+enum class AudioBackend {
+  kAuto,
+  kPulseAudio,
+  kSndio,
+  kAlsa
+};
+
+MEDIA_EXPORT BASE_DECLARE_FEATURE(kAudioBackend);
+MEDIA_EXPORT extern const base::FeatureParam<
+    AudioBackend>
+    kAudioBackendParam;
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_MAC)
