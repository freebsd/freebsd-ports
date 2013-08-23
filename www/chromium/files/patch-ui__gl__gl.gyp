--- ui/gl/gl.gyp.orig	2013-08-09 22:06:46.000000000 +0300
+++ ui/gl/gl.gyp	2013-08-16 21:35:40.000000000 +0300
@@ -178,7 +178,7 @@
         },
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
