--- ./ui/gl/gl.gyp.orig	2014-04-24 22:35:14.000000000 +0200
+++ ./ui/gl/gl.gyp	2014-04-24 23:23:48.000000000 +0200
@@ -170,7 +170,7 @@
         },
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
