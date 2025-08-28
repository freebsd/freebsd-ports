--- src/multimedia/configure.cmake.orig	2025-08-18 00:47:41 UTC
+++ src/multimedia/configure.cmake
@@ -129,7 +129,7 @@ qt_feature("ffmpeg" PRIVATE
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
     CONDITION FFmpeg_FOUND
-              AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio)
+              AND (APPLE OR WIN32 OR ANDROID OR QNX OR OR QT_FEATURE_alsa OR QT_FEATURE_pulseaudio)
               AND QT_FEATURE_thread
 )
 qt_feature("pipewire" PRIVATE
