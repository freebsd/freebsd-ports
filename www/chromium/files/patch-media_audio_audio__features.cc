--- media/audio/audio_features.cc.orig	2021-04-14 18:41:05 UTC
+++ media/audio/audio_features.cc
@@ -12,7 +12,7 @@ namespace features {
 // detected. It will be restarted when needed.
 const base::Feature kAudioServiceOutOfProcessKillAtHang{
   "AudioServiceOutOfProcessKillAtHang",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
