--- ./tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2014-08-20 21:04:18.000000000 +0200
+++ ./tools/gyp/test/additional-targets/src/dir1/actions.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -47,7 +47,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         'cflags': ['-fPIC'],
       },
