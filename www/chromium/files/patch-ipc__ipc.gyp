--- ./ipc/ipc.gyp.orig	2010-12-16 02:11:49.000000000 +0100
+++ ./ipc/ipc.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -62,7 +62,7 @@
             '../build/linux/system.gyp:gtk',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
