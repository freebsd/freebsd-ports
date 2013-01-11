--- media/media.gyp.orig	2012-11-27 10:01:14.000000000 +0200
+++ media/media.gyp	2012-11-28 22:11:36.000000000 +0200
@@ -470,7 +470,7 @@
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'variables': {
             'conditions': [
               ['sysroot!=""', {
@@ -1101,7 +1101,7 @@
         },
       ],
     }],
-    ['OS == "linux" and target_arch != "arm" and target_arch != "mipsel"', {
+    ['(OS == "linux" or OS == "freebsd") and target_arch != "arm" and target_arch != "mipsel"', {
       'targets': [
         {
           'target_name': 'tile_render_bench',
