--- ./third_party/libjpeg_turbo/libjpeg.gyp.orig	2014-04-24 22:36:33.000000000 +0200
+++ ./third_party/libjpeg_turbo/libjpeg.gyp	2014-04-24 23:23:48.000000000 +0200
@@ -240,7 +240,7 @@
             ],
           },
         }],
-        [ 'OS=="linux" or (OS=="android" and target_arch!="arm")', {
+        [ 'OS=="linux" or OS=="freebsd" or (OS=="android" and target_arch!="arm")', {
           'conditions': [
             [ 'use_system_yasm==0', {
               'dependencies': [
@@ -271,6 +271,9 @@
                 ],
               }],
             ],
+            'include_dirs': [
+              '<(prefix_dir)/include',
+            ],
           },
         }],
       ],
