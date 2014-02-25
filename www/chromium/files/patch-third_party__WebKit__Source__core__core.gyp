--- third_party/WebKit/Source/core/core.gyp.orig	2013-08-09 19:15:52.000000000 +0000
+++ third_party/WebKit/Source/core/core.gyp	2013-08-12 21:31:28.000000000 +0000
@@ -593,7 +593,7 @@
         ['exclude', 'platform/Theme\\.cpp$'],
       ],
       'conditions': [
-        ['OS!="linux"', {
+        ['OS!="linux" and os_bsd!=1', {
           'sources/': [
             ['exclude', 'Linux\\.cpp$'],
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
