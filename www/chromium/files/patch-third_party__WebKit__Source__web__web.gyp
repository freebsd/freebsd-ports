--- ./third_party/WebKit/Source/web/web.gyp.orig	2014-04-24 22:39:57.000000000 +0200
+++ ./third_party/WebKit/Source/web/web.gyp	2014-04-24 23:23:47.000000000 +0200
@@ -149,7 +149,7 @@
                       },
                     },
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
