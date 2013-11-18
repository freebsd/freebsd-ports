--- third_party/WebKit/Source/web/web.gyp.orig	2013-07-15 19:48:12.000000000 +0300
+++ third_party/WebKit/Source/web/web.gyp	2013-07-15 19:48:46.000000000 +0300
@@ -142,7 +142,7 @@
                       },
                     },
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
