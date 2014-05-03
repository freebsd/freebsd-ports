--- ./native_client/build/common.gypi.orig	2014-04-24 22:36:13.000000000 +0200
+++ ./native_client/build/common.gypi	2014-04-24 23:23:46.000000000 +0200
@@ -262,7 +262,7 @@
     ],
   },
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
