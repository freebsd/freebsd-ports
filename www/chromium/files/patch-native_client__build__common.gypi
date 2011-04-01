--- ./native_client/build/common.gypi.orig	2010-12-16 02:12:20.000000000 +0100
+++ ./native_client/build/common.gypi	2010-12-20 20:15:08.000000000 +0100
@@ -375,7 +375,7 @@
     },
   },
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
