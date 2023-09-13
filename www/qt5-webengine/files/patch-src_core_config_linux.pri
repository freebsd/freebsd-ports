--- src/core/config/linux.pri.orig	2021-12-15 16:12:54 UTC
+++ src/core/config/linux.pri
@@ -20,6 +20,12 @@ qtConfig(webengine-embedded-build) {
         gn_args += use_alsa=false
     }
 
+    qtConfig(webengine-sndio) {
+        gn_args += use_sndio=true
+    } else {
+        gn_args += use_sndio=false
+    }
+
     !packagesExist(libpci): gn_args += use_libpci=false
 
     qtConfig(webengine-ozone-x11) {
@@ -39,6 +45,6 @@ qtConfig(webengine-embedded-build) {
     qtConfig(webengine-system-libvpx):   gn_args += use_system_libvpx=true
     qtConfig(webengine-system-icu):      gn_args += use_system_icu=true icu_use_data_file=false
     qtConfig(webengine-system-ffmpeg):   gn_args += use_system_ffmpeg=true
-    qtConfig(webengine-system-re2):      gn_args += use_system_re2=true
+    qtConfig(webengine-system-re2):      gn_args += use_system_re2=false
     qtConfig(webengine-system-lcms2):    gn_args += use_system_lcms2=true
 }
