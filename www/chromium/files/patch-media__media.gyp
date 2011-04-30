--- media/media.gyp.orig	2011-04-21 21:52:13.846559129 +0300
+++ media/media.gyp	2011-04-21 21:52:29.930558911 +0300
@@ -612,7 +612,6 @@
           ],
           'libraries': [
             '-lGL',
-            '-ldl',
           ],
           'sources': [
             'tools/tile_render_bench/tile_render_bench.cc',
@@ -692,7 +691,6 @@
           ],
           'link_settings': {
             'libraries': [
-              '-ldl',
               '-lX11',
               '-lXrender',
               '-lXext',
