--- breakpad/breakpad.gyp.orig	2014-10-10 09:15:29 UTC
+++ breakpad/breakpad.gyp
@@ -353,7 +353,7 @@
         },
       ],
     }],
-    [ 'OS=="linux" or OS=="android" or OS=="freebsd"', {
+    [ 'OS=="linux" or OS=="android" or os_bsd==1', {
       'conditions': [
         ['OS=="android"', {
           'defines': [
