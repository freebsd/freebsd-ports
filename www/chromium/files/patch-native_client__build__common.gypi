--- native_client/build/common.gypi.orig	2014-10-10 09:16:25 UTC
+++ native_client/build/common.gypi
@@ -290,7 +290,7 @@
     ],
   },
   'conditions': [
-    ['OS=="linux" or OS=="android"', {
+    ['OS=="linux" or OS=="android" or OS=="freebsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
