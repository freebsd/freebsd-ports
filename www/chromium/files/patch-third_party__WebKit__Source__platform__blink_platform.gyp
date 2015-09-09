--- third_party/WebKit/Source/platform/blink_platform.gyp.orig	2015-09-01 16:10:53.000000000 -0400
+++ third_party/WebKit/Source/platform/blink_platform.gyp	2015-09-03 11:17:44.822976000 -0400
@@ -38,6 +38,9 @@
   'targets': [{
     'target_name': 'blink_common',
     'type': '<(component)',
+    'include_dirs': [
+      '<(prefix_dir)/include',
+    ],
     'variables': { 'enable_wexit_time_destructors': 1 },
     'dependencies': [
       '../config.gyp:config',
@@ -251,7 +254,7 @@
           ['include', 'graphics/cpu/x86/WebGLImageConversionSSE\\.h$'],
         ],
       }],
-      ['OS=="linux" or OS=="android" or OS=="win"', {
+      ['OS=="linux" or OS=="android" or OS=="win" or os_bsd==1', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/opentype/OpenTypeTypes\\.h$'],
@@ -262,7 +265,7 @@
         ],
       },
       ],
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or os_bsd==1', {
         'sources/': [
           ['include', 'fonts/linux/FontPlatformDataLinux\\.cpp$'],
         ]
@@ -345,7 +348,7 @@
           ['exclude', 'scroll/ScrollbarThemeMac'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and OS != "win"', {
+      ['OS != "linux" and OS != "mac" and OS != "win" and os_bsd != 1', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
@@ -388,7 +391,7 @@
           ['exclude', 'Android\\.cpp$'],
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or os_bsd==1', {
         'dependencies': [
           '<(DEPTH)/build/linux/system.gyp:fontconfig',
         ],
