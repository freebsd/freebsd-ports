--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-05-08 00:21:12.884604466 +0300
+++ third_party/ffmpeg/ffmpeg.gyp	2011-05-08 00:23:54.819604306 +0300
@@ -50,7 +50,7 @@
       }, {
         'ffmpeg_config%': '<(target_arch)',
       }],
-      ['OS=="mac" or OS=="win"', {
+      ['OS=="mac" or OS=="win" or OS=="freebsd"', {
         'os_config%': '<(OS)',
       }, {  # all other Unix OS's use the linux config
         'os_config%': 'linux',
@@ -205,8 +205,19 @@
               ],
             }],  # ffmpeg_branding
             ['target_arch=="ia32" or target_arch=="x64"', {
-              'dependencies': [
-                '../yasm/yasm.gyp:yasm#host',
+              'conditions': [
+                ['use_system_yasm==0', {
+                  'dependencies': [
+                    '../yasm/yasm.gyp:yasm#host',
+                  ],
+                  'variables': {
+                    'yasm_path': '<(PRODUCT_DIR)/yasm',
+                  },
+                }, {
+                  'variables': {
+                    'yasm_path': '<!(which yasm)',
+                  },
+                }],
               ],
               'sources': [
                 'patched-ffmpeg-mt/libavcodec/libvpxdec.c',
@@ -365,7 +376,6 @@
                 ],
               },
               'variables': {
-                'yasm_path': '<(PRODUCT_DIR)/yasm',
                 'obj_format': 'elf',
                 'conditions': [
                   [ 'target_arch=="ia32"', {
@@ -754,6 +764,10 @@
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
