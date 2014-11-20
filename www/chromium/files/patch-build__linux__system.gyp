--- build/linux/system.gyp.orig	2014-10-10 08:54:09 UTC
+++ build/linux/system.gyp
@@ -866,6 +866,13 @@
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
