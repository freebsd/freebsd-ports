--- third_party/WebKit/Source/platform/blink_platform.gyp.orig	2016-05-25 15:01:11.000000000 -0400
+++ third_party/WebKit/Source/platform/blink_platform.gyp	2016-05-27 12:20:28.640442000 -0400
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
@@ -222,7 +225,7 @@
           ['include', 'graphics/cpu/x86/WebGLImageConversionSSE\\.h$'],
         ],
       }],
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or os_bsd==1', {
         'sources/': [
           ['include', 'fonts/linux/FontPlatformDataLinux\\.cpp$'],
         ]
@@ -301,7 +304,7 @@
           ['exclude', 'scroll/ScrollbarThemeMac'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and OS != "win"', {
+      ['OS != "linux" and OS != "mac" and OS != "win" and os_bsd != 1', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
@@ -347,6 +350,11 @@
           ['exclude', 'scroll/ScrollbarThemeAura\\.(cpp|h)'],
         ],
       }],
+      ['use_system_icu==1', {
+        'defines': [
+          'USING_SYSTEM_ICU',
+        ],
+      }],
       ['"WTF_USE_WEBAUDIO_FFMPEG=1" in feature_defines', {
         'include_dirs': [
           '<(DEPTH)/third_party/ffmpeg',
