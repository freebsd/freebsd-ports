--- ./tools/gyp/test/library/src/library.gyp.orig	2014-04-30 22:44:27.000000000 +0200
+++ ./tools/gyp/test/library/src/library.gyp	2014-05-04 14:38:49.000000000 +0200
@@ -48,7 +48,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Support 64-bit shared libs (also works fine for 32-bit).
         'cflags': ['-fPIC'],
