--- app/app_base.gypi.orig	2011-04-13 10:01:07.000000000 +0200
+++ app/app_base.gypi	2011-04-17 22:15:49.000000000 +0200
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
@@ -363,7 +363,6 @@
             'link_settings': {
               'libraries': [
                 '-lX11',
-                '-ldl',
               ],
             },
           },
