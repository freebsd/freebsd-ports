--- src/multimedia/configure.cmake.orig	2023-10-03 20:42:53 UTC
+++ src/multimedia/configure.cmake
@@ -76,7 +76,7 @@ qt_feature("ffmpeg" PRIVATE
     LABEL "FFmpeg"
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
-    CONDITION FFmpeg_FOUND AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio)
+    CONDITION FFmpeg_FOUND AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_alsa OR QT_FEATURE_pulseaudio)
 )
 qt_feature("alsa" PUBLIC PRIVATE
     LABEL "ALSA (experimental)"
