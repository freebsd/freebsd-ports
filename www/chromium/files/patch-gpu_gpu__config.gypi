--- gpu/gpu_config.gypi.orig	2016-05-11 19:02:23 UTC
+++ gpu/gpu_config.gypi
@@ -71,7 +71,7 @@
         '../build/linux/system.gyp:libpci',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" or os_bsd==1) and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:x11',
         '../build/linux/system.gyp:xext',
@@ -79,5 +79,11 @@
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
