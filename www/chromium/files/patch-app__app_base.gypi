--- app/app_base.gypi.orig	2011-03-20 22:02:04.362467155 +0200
+++ app/app_base.gypi	2011-03-20 22:02:04.479736529 +0200
@@ -232,7 +232,7 @@
         'surface/io_surface_support_mac.cc',
         'surface/io_surface_support_mac.h',
         'surface/transport_dib.h',
-        'surface/transport_dib_linux.cc',
+	'surface/transport_dib_freebsd.cc',
         'surface/transport_dib_mac.cc',
         'surface/transport_dib_win.cc',
         'win/iat_patch_function.cc',
@@ -335,7 +335,7 @@
             ['exclude', '^win/*'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'sources': [
             'gfx/gl/gl_context_egl.cc',
             'gfx/gl/gl_context_egl.h',
