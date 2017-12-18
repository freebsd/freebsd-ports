--- Telegram/gyp/common.gypi.orig	2017-09-05 17:38:38 UTC
+++ Telegram/gyp/common.gypi
@@ -42,7 +42,7 @@
             }, {
               'build_mac': 0,
             }],
-            [ 'build_os == "linux"', {
+            [ 'build_os == "freebsd"', {
               'build_linux': 1,
             }, {
               'build_linux': 0,
