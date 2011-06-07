--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-05-06 12:05:13.000000000 +0300
+++ third_party/ffmpeg/ffmpeg.gyp	2011-06-05 17:22:39.293163655 +0300
@@ -50,7 +50,7 @@
       }, {
         'ffmpeg_config%': '<(target_arch)',
       }],
-      ['OS=="mac" or OS=="win"', {
+      ['OS=="mac" or OS=="win" or OS=="freebsd"', {
         'os_config%': '<(OS)',
       }, {  # all other Unix OS's use the linux config
         'os_config%': 'linux',
@@ -767,6 +767,10 @@
               'include_dirs': [
                 'config',
                 'patched-ffmpeg-mt',
+                # gliaskos: The following include is needed for libvpx,
+                # should remain _after_ patched-ffmpeg-mt or else
+                # ffmpeg_stubs.cc picks up system headers.
+                '/usr/local/include',
               ],
               'direct_dependent_settings': {
                 'include_dirs': [
