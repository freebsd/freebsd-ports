--- third_party/libjpeg_turbo/libjpeg.gyp.orig	2014-07-15 21:03:36.000000000 +0200
+++ third_party/libjpeg_turbo/libjpeg.gyp	2014-08-12 22:43:14.000000000 +0200
@@ -245,7 +245,7 @@
             ],
           },
         }],
-        [ 'OS=="linux" or OS=="freebsd" or (OS=="android" and target_arch!="arm")', {
+        [ 'OS=="linux" or os_bsd==1 or (OS=="android" and target_arch!="arm")', {
           'conditions': [
             [ 'use_system_yasm==0', {
               'dependencies': [
