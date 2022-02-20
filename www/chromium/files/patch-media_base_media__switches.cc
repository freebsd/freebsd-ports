--- media/base/media_switches.cc.orig	2022-02-07 13:39:41 UTC
+++ media/base/media_switches.cc
@@ -9,7 +9,7 @@
 #include "build/chromeos_buildflags.h"
 #include "components/system_media_controls/linux/buildflags/buildflags.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -397,7 +397,7 @@ const base::Feature kGav1VideoDecoder{"Gav1VideoDecode
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -429,7 +429,7 @@ constexpr base::FeatureParam<kCrosGlobalMediaControlsP
 const base::Feature kGlobalMediaControlsPictureInPicture {
   "GlobalMediaControlsPictureInPicture",
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
+    defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -470,7 +470,7 @@ const base::Feature kUseR16Texture{"use-r16-texture",
 const base::Feature kUnifiedAutoplay{"UnifiedAutoplay",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 const base::Feature kVaapiVideoDecodeLinux{"VaapiVideoDecoder",
@@ -926,7 +926,7 @@ bool IsLiveCaptionFeatureEnabled() {
     return false;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseSodaForLiveCaption)) {
     // Check if the CPU has the required instruction set to run the Speech
     // On-Device API (SODA) library.
