--- src/3rdparty/chromium/media/audio/audio_features.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/audio/audio_features.cc
@@ -19,7 +19,7 @@ const base::Feature kAudioServiceOutOfProcessKillAtHan
 const base::Feature kAudioServiceOutOfProcessKillAtHang{
   "AudioServiceOutOfProcessKillAtHang",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
