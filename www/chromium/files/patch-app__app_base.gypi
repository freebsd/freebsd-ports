--- app/app_base.gypi.orig	2011-04-21 23:19:08.067560122 +0300
+++ app/app_base.gypi	2011-04-21 23:19:47.444560550 +0300
@@ -234,6 +234,7 @@
         'surface/io_surface_support_mac.h',
         'surface/transport_dib.h',
         'surface/transport_dib_linux.cc',
+        'surface/transport_dib_freebsd.cc',
         'surface/transport_dib_mac.cc',
         'surface/transport_dib_win.cc',
         'win/iat_patch_function.cc',
@@ -334,7 +335,7 @@
             ['exclude', '^win/*'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'sources': [
             'gfx/gl/gl_context_egl.cc',
             'gfx/gl/gl_context_egl.h',
@@ -362,11 +363,15 @@
             'link_settings': {
               'libraries': [
                 '-lX11',
-                '-ldl',
               ],
             },
           },
         }],
+        ['OS=="freebsd" or OS=="openbsd"', {
+          'sources!': [
+            'surface/transport_dib_linux.cc',
+          ]
+        }],
         ['OS=="mac"', {
           'link_settings': {
             'libraries': [
