--- ./third_party/WebKit/Source/web/web.gyp.orig	2014-04-30 22:47:14.000000000 +0200
+++ ./third_party/WebKit/Source/web/web.gyp	2014-05-04 14:38:48.000000000 +0200
@@ -149,7 +149,7 @@
                       },
                     },
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
