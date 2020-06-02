--- media/audio/audio_features.cc.orig	2020-05-15 15:14:56 UTC
+++ media/audio/audio_features.cc
@@ -11,7 +11,7 @@ namespace features {
 // detected. It will be restarted when needed.
 const base::Feature kAudioServiceOutOfProcessKillAtHang{
   "AudioServiceOutOfProcessKillAtHang",
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
