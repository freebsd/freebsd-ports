--- src/buildtools/config/linux.pri.orig	2019-12-03 07:18:02 UTC
+++ src/buildtools/config/linux.pri
@@ -190,6 +190,11 @@ host_build {
     } else {
         gn_args += use_alsa=false
     }
+    qtConfig(webengine-sndio) {
+        gn_args += use_sndio=true
+    } else {
+        gn_args += use_sndio=false
+    }
     !packagesExist(libpci): gn_args += use_libpci=false
 
     qtConfig(webengine-ozone-x11) {
