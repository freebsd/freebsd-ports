--- media/media.gyp.orig	2011-10-10 20:58:23.652729836 +0000
+++ media/media.gyp	2011-10-10 20:58:50.086730237 +0000
@@ -248,7 +248,7 @@
             ],
           },
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'conditions': [
                 ['use_pulseaudio == 1', {
                   'link_settings': {
