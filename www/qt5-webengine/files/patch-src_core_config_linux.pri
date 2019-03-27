--- src/core/config/linux.pri.orig	2019-01-16 22:42:58 UTC
+++ src/core/config/linux.pri
@@ -166,6 +166,11 @@ host_build {
     } else {
         gn_args += use_alsa=false
     }
+    qtConfig(webengine-sndio) {
+        gn_args += use_sndio=true
+    } else {
+        gn_args += use_sndio=false
+    }
     !packagesExist(libpci): gn_args += use_libpci=false
 
     qtConfig(webengine-system-x11): hasX11Dependencies() {
