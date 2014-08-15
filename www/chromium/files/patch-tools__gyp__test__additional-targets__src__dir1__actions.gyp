--- ./tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2014-08-12 21:04:03.000000000 +0200
+++ ./tools/gyp/test/additional-targets/src/dir1/actions.gyp	2014-08-13 09:57:00.000000000 +0200
@@ -47,7 +47,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         'cflags': ['-fPIC'],
       },
