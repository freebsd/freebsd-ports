--- ./third_party/WebKit/Source/platform/blink_platform.gyp.orig	2014-04-30 22:47:17.000000000 +0200
+++ ./third_party/WebKit/Source/platform/blink_platform.gyp	2014-05-04 14:38:48.000000000 +0200
@@ -193,7 +193,7 @@
     # compiler optimizations, see crbug.com/237063
     'msvs_disabled_warnings': [ 4267, 4334, 4724 ],
     'conditions': [
-      ['OS=="linux" or OS=="android" or OS=="win"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd" or OS=="win"', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/harfbuzz/FontHarfBuzz\\.cpp$'],
@@ -303,7 +303,7 @@
           ['exclude', 'fonts/harfbuzz/HarfBuzzFaceCoreText\\.cpp$'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and OS != "win"', {
+      ['OS != "linux" and OS != "freebsd" and OS != "mac" and OS != "win"', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
