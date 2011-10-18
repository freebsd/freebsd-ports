--- ui/gfx/surface/surface.gyp.orig	2011-09-09 21:37:36.000000000 +0300
+++ ui/gfx/surface/surface.gyp	2011-09-09 21:45:23.000000000 +0300
@@ -14,6 +14,14 @@
           '<(DEPTH)/third_party/angle/include',
         ],
       }],
+      ['OS == "freebsd"', {
+        'sources!': [
+          'transport_dib_linux.cc',
+        ],
+        'sources': [
+          'transport_dib_freebsd.cc',
+        ],
+      }],
     ],
   },
   'targets': [
