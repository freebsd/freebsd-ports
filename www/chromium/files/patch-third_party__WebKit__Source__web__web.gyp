--- ./third_party/WebKit/Source/web/web.gyp.orig	2014-08-20 21:07:57.000000000 +0200
+++ ./third_party/WebKit/Source/web/web.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -142,7 +142,7 @@
                       },
                     },
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
