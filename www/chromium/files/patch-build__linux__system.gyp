--- ./build/linux/system.gyp.orig	2014-08-12 21:02:52.000000000 +0200
+++ ./build/linux/system.gyp	2014-08-13 09:56:56.000000000 +0200
@@ -885,6 +885,13 @@
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
