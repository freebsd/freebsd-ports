--- media/base/media_switches.cc.orig	2022-04-21 18:48:31 UTC
+++ media/base/media_switches.cc
@@ -10,7 +10,7 @@
 #include "components/system_media_controls/linux/buildflags/buildflags.h"
 #include "media/media_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #endif
 
@@ -410,7 +410,7 @@ const base::Feature kGav1VideoDecoder{"Gav1VideoDecode
 const base::Feature kGlobalMediaControls {
   "GlobalMediaControls",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -442,7 +442,7 @@ constexpr base::FeatureParam<kCrosGlobalMediaControlsP
 const base::Feature kGlobalMediaControlsPictureInPicture {
   "GlobalMediaControlsPictureInPicture",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -483,7 +483,7 @@ const base::Feature kUseR16Texture{"use-r16-texture",
 const base::Feature kUnifiedAutoplay{"UnifiedAutoplay",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable vaapi video decoding on linux. This is already enabled by default on
 // chromeos, but needs an experiment on linux.
 const base::Feature kVaapiVideoDecodeLinux{"VaapiVideoDecoder",
@@ -972,7 +972,7 @@ bool IsLiveCaptionFeatureEnabled() {
     return false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check if the CPU has the required instruction set to run the Speech
   // On-Device API (SODA) library.
   static bool has_sse41 = base::CPU().has_sse41();
