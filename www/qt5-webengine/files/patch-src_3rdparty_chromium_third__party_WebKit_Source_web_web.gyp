--- src/3rdparty/chromium/third_party/WebKit/Source/web/web.gyp.orig	2017-04-19 18:03:26 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/web/web.gyp
@@ -161,7 +161,7 @@
                         '../core/core.gyp:webcore',
                      ],
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
