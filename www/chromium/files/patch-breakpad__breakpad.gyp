--- breakpad/breakpad.gyp.orig	2014-01-07 21:02:21.000000000 +0100
+++ breakpad/breakpad.gyp	2014-01-12 22:55:47.000000000 +0100
@@ -334,7 +334,7 @@
         },
       ],
     }],
-    [ 'OS=="linux" or OS=="android"', {
+    [ 'OS=="linux" or OS=="android" or os_bsd==1', {
       'conditions': [
         ['OS=="android"', {
           'defines': [
