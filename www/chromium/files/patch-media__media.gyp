--- media/media.gyp.orig	2013-04-30 10:22:14.000000000 +0300
+++ media/media.gyp	2013-05-08 21:54:11.000000000 +0300
@@ -598,7 +598,7 @@
             'audio/openbsd/audio_manager_openbsd.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'variables': {
             'conditions': [
               ['sysroot!=""', {
