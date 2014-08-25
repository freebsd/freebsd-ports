--- ./breakpad/breakpad.gyp.orig	2014-08-20 21:02:30.000000000 +0200
+++ ./breakpad/breakpad.gyp	2014-08-22 15:06:24.000000000 +0200
@@ -340,7 +340,7 @@
         },
       ],
     }],
-    [ 'OS=="linux" or OS=="android" or OS=="freebsd"', {
+    [ 'OS=="linux" or OS=="android" or os_bsd==1', {
       'conditions': [
         ['OS=="android"', {
           'defines': [
