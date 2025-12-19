--- src/multimedia/configure.cmake.orig	2025-08-15 19:16:13 UTC
+++ src/multimedia/configure.cmake
@@ -237,7 +237,7 @@ qt_feature("ffmpeg" PRIVATE
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
     CONDITION FFmpeg_FOUND
-              AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio OR QT_FEATURE_pipewire)
+              AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_alsa OR QT_FEATURE_pulseaudio OR QT_FEATURE_pipewire)
               AND QT_FEATURE_thread
 )
 
