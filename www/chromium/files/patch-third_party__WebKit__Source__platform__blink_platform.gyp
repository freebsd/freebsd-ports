--- third_party/WebKit/Source/platform/blink_platform.gyp.orig	2015-01-21 20:48:07 UTC
+++ third_party/WebKit/Source/platform/blink_platform.gyp
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
@@ -248,7 +251,7 @@
     # compiler optimizations, see crbug.com/237063
     'msvs_disabled_warnings': [ 4267, 4334, 4724 ],
     'conditions': [
-      ['OS=="linux" or OS=="android" or OS=="win"', {
+      ['OS=="linux" or OS=="android" or OS=="win" or os_bsd==1', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/opentype/OpenTypeTypes\\.h$'],
@@ -259,7 +262,7 @@
         ],
       },
       ],
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or os_bsd==1', {
         'sources/': [
           ['include', 'fonts/linux/FontPlatformDataLinux\\.cpp$'],
         ]
@@ -350,7 +353,7 @@
           ['exclude', 'scroll/ScrollbarThemeMac'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and OS != "win"', {
+      ['OS != "linux" and OS != "mac" and OS != "win" and os_bsd != 1', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
@@ -395,7 +398,7 @@
           ['exclude', 'Android\\.cpp$'],
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or os_bsd==1', {
         'dependencies': [
           '<(DEPTH)/build/linux/system.gyp:fontconfig',
         ],
