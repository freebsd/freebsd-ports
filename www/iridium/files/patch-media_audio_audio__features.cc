--- media/audio/audio_features.cc.orig	2022-10-05 07:34:01 UTC
+++ media/audio/audio_features.cc
@@ -14,7 +14,7 @@ namespace features {
 const base::Feature kAudioServiceOutOfProcessKillAtHang{
   "AudioServiceOutOfProcessKillAtHang",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
