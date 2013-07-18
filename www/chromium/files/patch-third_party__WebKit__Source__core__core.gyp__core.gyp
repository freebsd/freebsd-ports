--- third_party/WebKit/Source/core/core.gyp/core.gyp.orig	2013-07-15 19:52:51.000000000 +0300
+++ third_party/WebKit/Source/core/core.gyp/core.gyp	2013-07-15 19:58:35.000000000 +0300
@@ -608,7 +608,7 @@
             ['exclude', 'platform/chromium/ScrollbarThemeChromiumDefault.h'],
           ],
         }],
-        ['OS=="linux" or OS=="android"', {
+        ['OS=="linux" or OS=="android" or os_bsd==1', {
           'sources/': [
             # Cherry-pick files excluded by the broader regular expressions above.
             ['include', 'platform/graphics/harfbuzz/FontHarfBuzz\\.cpp$'],
@@ -629,7 +629,7 @@
             ['exclude', 'Harfbuzz[^/]+\\.(cpp|h)$'],
           ],
         }],
-        ['OS!="linux"', {
+        ['OS!="linux" and os_bsd!=1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -740,7 +740,7 @@
             ['exclude', 'platform/graphics/FontPlatformData\\.cpp$'],
           ],
         }],
-        ['OS != "linux" and OS != "mac"', {
+        ['OS != "linux" and OS != "mac" and os_bsd != 1', {
           'sources/': [
             ['exclude', 'VDMX[^/]+\\.(cpp|h)$'],
           ],
@@ -900,7 +900,7 @@
           # Due to a bug in gcc 4.6 in android NDK, we get warnings about uninitialized variable.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
@@ -945,7 +945,7 @@
         ['OS=="win" and buildtype=="Official"', {
           'msvs_shard': 19,
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
           ],
