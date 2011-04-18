--- media/media.gyp.orig	2011-04-17 22:22:00.000000000 +0200
+++ media/media.gyp	2011-04-17 22:22:15.000000000 +0200
@@ -600,7 +600,6 @@
           ],
           'link_settings': {
             'libraries': [
-              '-ldl',
               '-lX11',
               '-lXrender',
               '-lXext',
