--- ./chrome/chrome_renderer.gypi.orig	2010-12-16 02:12:13.000000000 +0100
+++ ./chrome/chrome_renderer.gypi	2010-12-20 20:15:08.000000000 +0100
@@ -285,6 +285,14 @@
         }],
         # BSD-specific rules.
         ['OS=="openbsd" or OS=="freebsd"', {
+          'conditions': [
+            [ 'linux_use_tcmalloc==1', {
+                'dependencies': [
+                  '../base/allocator/allocator.gyp:allocator',
+                ],
+	      },
+	    ],
+	  ],
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
