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
