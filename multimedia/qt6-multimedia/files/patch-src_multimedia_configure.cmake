--- src/multimedia/configure.cmake.orig	2024-03-19 05:09:26 UTC
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
@@ -101,7 +101,7 @@ qt_feature("gstreamer_1_0" PRIVATE
 )
 qt_feature("gstreamer_1_0" PRIVATE
     LABEL "GStreamer 1.0"
-    CONDITION ( LINUX AND GStreamer_FOUND )
+    CONDITION GStreamer_FOUND
     ENABLE INPUT_gstreamer STREQUAL 'yes'
     DISABLE INPUT_gstreamer STREQUAL 'no'
 )
