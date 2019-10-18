--- Telegram/gyp/common/common.gypi.orig	2019-10-07 15:58:21 UTC
+++ Telegram/gyp/common/common.gypi
@@ -29,7 +29,7 @@
             }, {
               'build_mac': 0,
             }],
-            [ 'build_os == "linux"', {
+            [ 'build_os == "freebsd"', {
               'build_linux': 1,
             }, {
               'build_linux': 0,
