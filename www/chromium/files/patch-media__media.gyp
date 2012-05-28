--- media/media.gyp.orig	2012-04-25 10:01:21.000000000 +0300
+++ media/media.gyp	2012-04-30 00:26:41.000000000 +0300
@@ -341,7 +341,7 @@
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'variables': {
             'conditions': [
               ['sysroot!=""', {
@@ -858,7 +858,7 @@
         },
       ],
     }],
-    ['OS == "linux" and target_arch != "arm"', {
+    ['(OS == "linux" or OS == "freebsd") and target_arch != "arm"', {
       'targets': [
         {
           'target_name': 'tile_render_bench',
