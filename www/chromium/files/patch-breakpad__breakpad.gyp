--- ./breakpad/breakpad.gyp.orig	2014-08-12 21:02:55.000000000 +0200
+++ ./breakpad/breakpad.gyp	2014-08-13 09:56:56.000000000 +0200
@@ -340,7 +340,7 @@
         },
       ],
     }],
-    [ 'OS=="linux" or OS=="android" or OS=="freebsd"', {
+    [ 'OS=="linux" or OS=="android" or os_bsd==1', {
       'conditions': [
         ['OS=="android"', {
           'defines': [
