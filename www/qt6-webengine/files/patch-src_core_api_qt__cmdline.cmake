--- src/core/api/qt_cmdline.cmake.orig	2025-08-15 18:30:00 UTC
+++ src/core/api/qt_cmdline.cmake
@@ -28,7 +28,7 @@ set(systemLibs alsa ffmpeg freetype harfbuzz icu lcms2
 endfunction()
 
 set(systemLibs alsa ffmpeg freetype harfbuzz icu lcms2 libjpeg
-    libpng libvpx libxml libwebp minizip opus pulseaudio re2 snappy zlib)
+    libpng libvpx libxml libwebp minizip opus pulseaudio re2 snappy sndio zlib)
 foreach(slib ${systemLibs})
     qt_commandline_option(webengine-${slib} TYPE enum NAME webengine-system-${slib} VALUES yes no system)
 endforeach()
