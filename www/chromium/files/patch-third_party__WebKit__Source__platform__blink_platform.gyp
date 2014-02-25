--- third_party/WebKit/Source/platform/blink_platform.gyp.orig	2014-02-20 21:32:30.000000000 +0100
+++ third_party/WebKit/Source/platform/blink_platform.gyp	2014-02-25 01:06:25.000000000 +0100
@@ -196,7 +196,7 @@
     # compiler optimizations, see crbug.com/237063
     'msvs_disabled_warnings': [ 4267, 4334, 4724 ],
     'conditions': [
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd"', {
         'sources/': [
           # Cherry-pick files excluded by the broader regular expressions above.
           ['include', 'fonts/harfbuzz/FontHarfBuzz\\.cpp$'],
@@ -304,7 +304,7 @@
           ['exclude', 'fonts/harfbuzz/HarfBuzzFaceCoreText\\.cpp$'],
         ],
       }],
-      ['OS != "linux" and OS != "mac" and (OS != "win" or (OS == "win" and "ENABLE_GDI_FONTS_ON_WINDOWS=1" in feature_defines))', {
+      ['OS != "linux" and OS != "freebsd" and OS != "mac" and (OS != "win" or (OS == "win" and "ENABLE_GDI_FONTS_ON_WINDOWS=1" in feature_defines))', {
         'sources/': [
           ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
         ],
