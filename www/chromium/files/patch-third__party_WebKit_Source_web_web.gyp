--- third_party/WebKit/Source/web/web.gyp.orig	2016-05-11 19:02:33 UTC
+++ third_party/WebKit/Source/web/web.gyp
@@ -160,7 +160,7 @@
                         '../core/core.gyp:webcore',
                      ],
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
