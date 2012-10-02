--- third_party/libjpeg_turbo/libjpeg.gyp.orig	2012-09-25 16:03:33.000000000 +0300
+++ third_party/libjpeg_turbo/libjpeg.gyp	2012-09-29 18:07:42.000000000 +0300
@@ -231,7 +231,7 @@
             ],
           },
         }],
-        [ 'OS=="linux" or (OS=="android" and target_arch!="arm")', {
+        [ 'OS=="linux" or OS=="freebsd" or (OS=="android" and target_arch!="arm")', {
           'conditions': [
             [ 'use_system_yasm==0', {
               'dependencies': [
@@ -262,6 +262,9 @@
                 ],
               }],
             ],
+            'include_dirs': [
+              '<(prefix_dir)/include',
+            ],
           },
         }],
       ],
