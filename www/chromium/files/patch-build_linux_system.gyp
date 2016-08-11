--- build/linux/system.gyp.orig	2016-05-11 19:02:12 UTC
+++ build/linux/system.gyp
@@ -1051,6 +1051,13 @@
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
