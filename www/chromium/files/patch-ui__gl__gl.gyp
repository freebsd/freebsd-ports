--- ./ui/gl/gl.gyp.orig	2014-08-12 21:02:27.000000000 +0200
+++ ./ui/gl/gl.gyp	2014-08-13 09:57:00.000000000 +0200
@@ -173,7 +173,7 @@
         },
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
@@ -192,7 +192,7 @@
             '<(DEPTH)/third_party/khronos',
         ],
         }],
-        ['OS in ("android", "linux")', {
+        ['OS in ("android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'gl_implementation_osmesa.cc',
             'gl_implementation_osmesa.h',
