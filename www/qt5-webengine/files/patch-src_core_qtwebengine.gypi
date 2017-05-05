--- src/core/qtwebengine.gypi.orig	2017-04-19 08:40:53 UTC
+++ src/core/qtwebengine.gypi
@@ -109,7 +109,7 @@
         # TODO(jschuh): crbug.com/167187 fix size_t to int truncations.
         'msvs_disabled_warnings': [ 4267, 4996, ],
       }],  # OS=="win"
-      ['OS=="linux"', {
+      ['os_posix==1', {
         'dependencies': [
           '<(chromium_src_dir)/build/linux/system.gyp:fontconfig',
         ],
