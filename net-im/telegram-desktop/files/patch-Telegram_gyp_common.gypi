--- Telegram/gyp/common.gypi.orig	2018-08-04 18:53:40 UTC
+++ Telegram/gyp/common.gypi
@@ -29,7 +29,7 @@
             }, {
               'build_mac': 0,
             }],
-            [ 'build_os == "linux"', {
+            [ 'build_os == "freebsd"', {
               'build_linux': 1,
             }, {
               'build_linux': 0,
