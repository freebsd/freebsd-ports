--- ./third_party/mesa/mesa.gyp.orig	2010-12-16 02:11:42.000000000 +0100
+++ ./third_party/mesa/mesa.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -19,7 +19,7 @@
           'HAVE_STRNLEN',
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'cflags': [
           '-fPIC',
         ],
