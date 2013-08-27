--- third_party/WebKit/Source/core/core.gyp.orig	2013-08-09 19:15:52.000000000 +0000
+++ third_party/WebKit/Source/core/core.gyp	2013-08-12 21:31:28.000000000 +0000
@@ -644,7 +644,7 @@
             ['exclude', 'platform/chromium/ScrollbarThemeChromiumDefault.h'],
           ],
         }],
-        ['OS=="linux" or OS=="android"', {
+        ['OS=="linux" or OS=="android" or os_bsd==1', {
           'sources/': [
             # Cherry-pick files excluded by the broader regular expressions above.
             ['include', 'platform/graphics/harfbuzz/FontHarfBuzz\\.cpp$'],
@@ -665,7 +665,7 @@
             ['exclude', 'Harfbuzz[^/]+\\.(cpp|h)$'],
           ],
         }],
-        ['OS!="linux"', {
+        ['OS!="linux" and os_bsd!=1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -775,7 +775,7 @@
             ['exclude', 'platform/graphics/FontPlatformData\\.cpp$'],
           ],
         }],
-        ['OS != "linux" and OS != "mac" and (OS != "win" or (OS == "win" and "ENABLE_GDI_FONTS_ON_WINDOWS=1" in feature_defines))', {
+        ['OS != "linux" and OS != "mac" and os_bsd != 1 and (OS != "win" or (OS == "win" and "ENABLE_GDI_FONTS_ON_WINDOWS=1" in feature_defines))', {
           'sources/': [
             ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
           ],
@@ -946,7 +946,7 @@
           # Due to a bug in gcc 4.6 in android NDK, we get warnings about uninitialized variable.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -991,7 +991,7 @@
         ['OS=="win" and buildtype=="Official"', {
           'msvs_shard': 19,
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
