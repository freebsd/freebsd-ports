--- media/base/media_switches.cc.orig	2021-04-20 18:58:34 UTC
+++ media/base/media_switches.cc
@@ -375,7 +375,7 @@ const base::Feature kGav1VideoDecoder{"Gav1VideoDecode
 // Show toolbar button that opens dialog for controlling media sessions.
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -417,7 +417,7 @@ const base::Feature kGlobalMediaControlsOverlayControl
 // Show picture-in-picture button in Global Media Controls.
 const base::Feature kGlobalMediaControlsPictureInPicture {
   "GlobalMediaControlsPictureInPicture",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -461,7 +461,7 @@ const base::Feature kUnifiedAutoplay{"UnifiedAutoplay"
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 const base::Feature kVaapiVideoDecodeLinux{"VaapiVideoDecoder",
@@ -469,7 +469,7 @@ const base::Feature kVaapiVideoDecodeLinux{"VaapiVideo
 
 const base::Feature kVaapiVideoEncodeLinux{"VaapiVideoEncoder",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 // Enable VA-API hardware decode acceleration for AV1.
 const base::Feature kVaapiAV1Decoder{"VaapiAV1Decoder",
