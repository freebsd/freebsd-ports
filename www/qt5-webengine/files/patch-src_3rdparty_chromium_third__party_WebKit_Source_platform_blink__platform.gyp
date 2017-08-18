--- src/3rdparty/chromium/third_party/WebKit/Source/platform/blink_platform.gyp.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/blink_platform.gyp
@@ -203,7 +204,7 @@
           ['include', 'graphics/cpu/x86/WebGLImageConversionSSE\\.h$'],
         ],
       }],
-      ['OS=="linux" or OS=="android" or OS=="win"', {
+      ['OS=="linux" or OS=="android" or OS=="win" or os_bsd==1', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/opentype/OpenTypeTypes\\.h$'],
@@ -214,7 +215,7 @@
         ],
       },
       ],
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or os_bsd==1', {
         'sources/': [
           ['include', 'fonts/linux/FontPlatformDataLinux\\.cpp$'],
         ]
@@ -307,7 +308,7 @@
           ['exclude', 'scroll/ScrollbarThemeMac'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and OS != "win"', {
+      ['OS != "linux" and OS != "mac" and OS != "win" and os_bsd != 1', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
@@ -350,7 +351,7 @@
           ['exclude', 'Android\\.cpp$'],
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or os_bsd==1', {
         'dependencies': [
           '<(DEPTH)/build/linux/system.gyp:fontconfig',
         ],
