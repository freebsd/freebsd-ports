--- ./build/linux/system.gyp.orig	2014-08-20 21:02:29.000000000 +0200
+++ ./build/linux/system.gyp	2014-08-22 15:06:24.000000000 +0200
@@ -881,6 +881,13 @@
       'include_dirs': [
         '../..',
       ],
+      'conditions' : [
+        ['OS=="freebsd"', {
+          'include_dirs': [
+            '<(prefix_dir)/include',
+          ],
+        }],
+      ],
       'hard_dependency': 1,
       'actions': [
         {
