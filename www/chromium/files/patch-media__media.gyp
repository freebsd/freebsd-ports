--- media/media.gyp.orig	2011-11-01 10:42:28.000000000 +0200
+++ media/media.gyp	2011-11-22 00:34:45.000000000 +0200
@@ -293,7 +293,7 @@
             ],
           },
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'conditions': [
                 ['use_pulseaudio == 1', {
                   'link_settings': {
@@ -479,7 +479,7 @@
             ],
           },
         }],
-        [ 'OS=="linux"', {
+        [ 'OS=="linux" or OS=="freebsd"', {
           'variables': {
             'conditions': [
               [ 'target_arch=="ia32"', {
@@ -765,7 +765,7 @@
         },
       ],
     }],
-    ['OS == "linux" and target_arch != "arm"', {
+    ['(OS == "linux" or OS == "freebsd") and target_arch != "arm"', {
       'targets': [
         {
           'target_name': 'tile_render_bench',
