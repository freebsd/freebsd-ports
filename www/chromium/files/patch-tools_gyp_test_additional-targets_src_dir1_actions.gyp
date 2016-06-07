--- tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2016-05-11 19:04:05 UTC
+++ tools/gyp/test/additional-targets/src/dir1/actions.gyp
@@ -47,7 +47,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         'cflags': ['-fPIC'],
       },
