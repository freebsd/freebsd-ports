--- ui/gfx/surface/surface.gyp.orig	2011-06-29 21:20:25.308574273 +0300
+++ ui/gfx/surface/surface.gyp	2011-06-29 21:24:36.234570454 +0300
@@ -13,10 +13,20 @@
       ['toolkit_uses_gtk == 1', {
         'sources/': [
           ['include', '/gtk/'],
-          ['include', '_(gtk|linux|posix|skia|x)\\.cc$'],
+          ['include', '_(gtk|posix|skia|x)\\.cc$'],
           ['include', '/(gtk|x11)_[^/]*\\.cc$'],
         ],
       }],
+      ['OS=="linux"', {
+        'sources/': [
+          ['include', '_linux\\.cc$'],
+        ],
+      }],
+      ['OS=="freebsd"', {
+        'sources/': [
+          ['include', '_freebsd\\.cc$'],
+        ],
+      }],
       ['OS=="mac"', {'sources/': [
         ['include', '/cocoa/'],
         ['include', '_(cocoa|mac|posix)\\.(cc|mm?)$'],
@@ -53,6 +63,7 @@
         'transport_dib_linux.cc',
         'transport_dib_mac.cc',
         'transport_dib_win.cc',
+        'transport_dib_freebsd.cc',
       ],
     },
   ],
