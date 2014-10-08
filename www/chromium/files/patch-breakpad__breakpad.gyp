--- breakpad/breakpad.gyp.orig	2014-10-02 17:39:45 UTC
+++ breakpad/breakpad.gyp
@@ -349,7 +349,7 @@
         },
       ],
     }],
-    [ 'OS=="linux" or OS=="android" or OS=="freebsd"', {
+    [ 'OS=="linux" or OS=="android" or os_bsd==1', {
       'conditions': [
         ['OS=="android"', {
           'defines': [
