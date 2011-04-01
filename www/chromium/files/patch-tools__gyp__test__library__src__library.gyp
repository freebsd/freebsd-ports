--- ./tools/gyp/test/library/src/library.gyp.orig	2010-12-16 02:33:32.000000000 +0100
+++ ./tools/gyp/test/library/src/library.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -48,7 +48,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Support 64-bit shared libs (also works fine for 32-bit).
         'cflags': ['-fPIC'],
