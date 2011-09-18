--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-09-14 02:43:26.000000000 +0300
+++ third_party/ffmpeg/ffmpeg.gyp	2011-09-14 03:03:08.000000000 +0300
@@ -528,6 +528,9 @@
                      'libraries': [
                        '-lvpx',
                      ],
+                     'ldflags': [
+                       '-L<(prefix_dir)/lib',
+                     ],
                    }],
                 ],
               },
@@ -642,7 +645,7 @@
               }, {
                 # Using libvpx provided by the system.
                 'include_dirs': [
-                  '/usr/include/vpx',
+                  '<(prefix_dir)/include',
                 ],
               }
             ],
@@ -941,6 +944,7 @@
               'include_dirs': [
                 'config',
                 'patched-ffmpeg',
+                '<(prefix_dir)/include',
               ],
               'direct_dependent_settings': {
                 'include_dirs': [
