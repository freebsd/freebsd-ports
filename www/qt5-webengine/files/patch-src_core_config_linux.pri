--- src/core/config/linux.pri.orig	2018-06-21 17:19:26 UTC
+++ src/core/config/linux.pri
@@ -136,6 +136,11 @@ host_build {
     } else {
         gn_args += use_alsa=false
     }
+    qtConfig(sndio) {
+        gn_args += use_sndio=true
+    } else {
+        gn_args += use_sndio=false
+    }
     packagesExist(libffi): gn_args += use_system_libffi=true
     else: gn_args += use_system_libffi=false
     !packagesExist(libpci): gn_args += use_libpci=false
