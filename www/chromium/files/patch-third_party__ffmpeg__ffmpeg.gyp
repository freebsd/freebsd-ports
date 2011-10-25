--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-10-07 11:34:35.000000000 +0300
+++ third_party/ffmpeg/ffmpeg.gyp	2011-10-08 22:31:59.259508048 +0300
@@ -508,6 +508,7 @@
               'include_dirs': [
                 'config',
                 'patched-ffmpeg',
+                '<(prefix_dir)/include',
               ],
               'direct_dependent_settings': {
                 'include_dirs': [
