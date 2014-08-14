--- ./native_client/build/common.gypi.orig	2014-08-12 21:03:33.000000000 +0200
+++ ./native_client/build/common.gypi	2014-08-13 09:56:57.000000000 +0200
@@ -269,7 +269,7 @@
     ],
   },
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
