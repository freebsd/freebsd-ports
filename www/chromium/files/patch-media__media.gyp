--- media/media.gyp.orig	2012-01-18 11:11:21.000000000 +0200
+++ media/media.gyp	2012-01-29 19:28:14.000000000 +0200
@@ -804,7 +804,7 @@
         },
       ],
     }],
-    ['OS == "linux" and target_arch != "arm"', {
+    ['(OS == "linux" or OS == "freebsd") and target_arch != "arm"', {
       'targets': [
         {
           'target_name': 'tile_render_bench',
