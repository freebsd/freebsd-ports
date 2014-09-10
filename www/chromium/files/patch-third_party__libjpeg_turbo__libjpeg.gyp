--- ./third_party/libjpeg_turbo/libjpeg.gyp.orig	2014-08-20 21:03:45.000000000 +0200
+++ ./third_party/libjpeg_turbo/libjpeg.gyp	2014-08-21 23:18:11.000000000 +0200
@@ -245,7 +245,7 @@
             ],
           },
         }],
-        [ 'OS=="linux" or OS=="freebsd" or (OS=="android" and target_arch!="arm")', {
+        [ 'OS=="linux" or os_bsd==1 or (OS=="android" and target_arch!="arm")', {
           'conditions': [
             [ 'use_system_yasm==0', {
               'dependencies': [
