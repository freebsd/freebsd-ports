--- native_client/build/common.gypi.orig	2016-01-14 01:27:44.000000000 +0100
+++ native_client/build/common.gypi	2016-01-21 16:23:12.810024295 +0100
@@ -275,7 +275,7 @@
     ],
   },
   'conditions': [
-    ['OS=="linux" or OS=="android"', {
+    ['OS=="linux" or OS=="android" or OS=="freebsd"', {
       'target_defaults': {
         # Enable -Werror by default, but put it in a variable so it can
         # be disabled in ~/.gyp/include.gypi on the valgrind builders.
