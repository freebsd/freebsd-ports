--- ./third_party/WebKit/Source/web/web.gyp.orig	2014-08-12 21:07:15.000000000 +0200
+++ ./third_party/WebKit/Source/web/web.gyp	2014-08-13 09:56:58.000000000 +0200
@@ -142,7 +142,7 @@
                       },
                     },
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
