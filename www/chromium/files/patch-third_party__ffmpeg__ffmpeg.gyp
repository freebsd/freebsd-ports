--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-03-28 21:25:33.000000000 +0200
+++ third_party/ffmpeg/ffmpeg.gyp	2011-03-28 21:28:28.000000000 +0200
@@ -56,7 +56,7 @@
       ['target_arch=="arm"', {
         'ffmpeg_asm_lib': 0,
       }],
-      ['OS=="mac" or OS=="win"', {
+      ['OS=="mac" or OS=="win" or OS=="freebsd"', {
         'os_config%': '<(OS)',
       }, {  # all other Unix OS's use the linux config
         'os_config%': 'linux',
