--- src/3rdparty/chromium/ui/gl/gl.gyp.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/ui/gl/gl.gyp
@@ -132,7 +132,7 @@
         'trace_util.h',
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
@@ -150,7 +150,7 @@
             'gl_surface_egl.h',
           ],
         }],
-        ['OS in ("android", "linux")', {
+        ['OS in ("android", "linux", "freebsd")', {
           'sources': [
             'gl_implementation_osmesa.cc',
             'gl_implementation_osmesa.h',
