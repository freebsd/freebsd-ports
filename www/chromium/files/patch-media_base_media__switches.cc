--- media/base/media_switches.cc.orig	2021-09-24 04:26:07 UTC
+++ media/base/media_switches.cc
@@ -9,7 +9,7 @@
 #include "build/chromeos_buildflags.h"
 #include "components/system_media_controls/linux/buildflags/buildflags.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -420,7 +420,7 @@ const base::Feature kGav1VideoDecoder{"Gav1VideoDecode
 // Show toolbar button that opens dialog for controlling media sessions.
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -462,7 +462,7 @@ const base::Feature kGlobalMediaControlsOverlayControl
 // Show picture-in-picture button in Global Media Controls.
 const base::Feature kGlobalMediaControlsPictureInPicture {
   "GlobalMediaControlsPictureInPicture",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -504,7 +504,7 @@ const base::Feature kUseR16Texture{"use-r16-texture",
 const base::Feature kUnifiedAutoplay{"UnifiedAutoplay",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 const base::Feature kVaapiVideoDecodeLinux{"VaapiVideoDecoder",
@@ -512,7 +512,7 @@ const base::Feature kVaapiVideoDecodeLinux{"VaapiVideo
 
 const base::Feature kVaapiVideoEncodeLinux{"VaapiVideoEncoder",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // Enable VA-API hardware decode acceleration for AV1.
 const base::Feature kVaapiAV1Decoder{"VaapiAV1Decoder",
@@ -938,7 +938,7 @@ bool IsLiveCaptionFeatureEnabled() {
     return false;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseSodaForLiveCaption)) {
     // Check if the CPU has the required instruction set to run the Speech
     // On-Device API (SODA) library.
