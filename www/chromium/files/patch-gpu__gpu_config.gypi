--- gpu/gpu_config.gypi.orig	2015-04-19 16:30:17.000000000 +0200
+++ gpu/gpu_config.gypi	2015-04-19 16:33:04.000000000 +0200
@@ -70,7 +70,7 @@
         '../build/linux/system.gyp:libpci',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" or os_bsd==1) and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:x11',
         '../build/linux/system.gyp:xext',
@@ -78,5 +78,11 @@
         '../ui/gfx/x/gfx_x11.gyp:gfx_x11',
       ],
     }],
+    ['os_bsd==1', {
+      'sources!': [
+        'config/gpu_info_collector_linux.cc',
+        'config/gpu_info_collector_linux.h',
+      ],
+    }]
   ],
 }
