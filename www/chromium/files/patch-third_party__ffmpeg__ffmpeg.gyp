--- third_party/ffmpeg/ffmpeg.gyp.orig	2011-04-26 11:02:53.000000000 +0300
+++ third_party/ffmpeg/ffmpeg.gyp	2011-04-29 01:18:16.629475671 +0300
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
@@ -720,6 +730,12 @@
               },
             }],
 
+            ['OS=="freebsd" and use_system_vpx==1', {
+              'include_dirs': [
+                '/usr/local/include',
+              ],
+            }],
+
             ['use_system_vpx==0', {
               'include_dirs': [
                 # TODO(fischman): when both mac & linux are building from
