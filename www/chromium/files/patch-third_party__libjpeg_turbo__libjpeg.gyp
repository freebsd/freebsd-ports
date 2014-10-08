--- third_party/libjpeg_turbo/libjpeg.gyp.orig	2014-09-04 00:29:24 UTC
+++ third_party/libjpeg_turbo/libjpeg.gyp
@@ -246,7 +246,7 @@
             ],
           },
         }],
-        [ 'OS=="linux" or OS=="freebsd" or (OS=="android" and (target_arch=="ia32" or target_arch=="x64"))', {
+        [ 'OS=="linux" or os_bsd==1 or (OS=="android" and (target_arch=="ia32" or target_arch=="x64"))', {
           'conditions': [
             [ 'use_system_yasm==0', {
               'dependencies': [
