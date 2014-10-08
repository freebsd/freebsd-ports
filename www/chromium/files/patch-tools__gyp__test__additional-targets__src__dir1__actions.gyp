--- tools/gyp/test/additional-targets/src/dir1/actions.gyp.orig	2014-10-02 17:40:30 UTC
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
