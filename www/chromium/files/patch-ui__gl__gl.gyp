--- ./ui/gl/gl.gyp.orig	2014-08-20 21:02:15.000000000 +0200
+++ ./ui/gl/gl.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -171,7 +171,7 @@
         },
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
@@ -190,7 +190,7 @@
             '<(DEPTH)/third_party/khronos',
         ],
         }],
-        ['OS in ("android", "linux")', {
+        ['OS in ("android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'gl_implementation_osmesa.cc',
             'gl_implementation_osmesa.h',
