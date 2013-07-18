--- tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2010-12-16 02:33:31.000000000 +0100
+++ tools/gyp/test/additional-targets/src/dir1/actions.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -47,7 +47,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         'cflags': ['-fPIC'],
       },
