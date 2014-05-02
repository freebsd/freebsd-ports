--- ./third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-04-24 22:36:00.000000000 +0200
+++ ./third_party/libXNVCtrl/libXNVCtrl.gyp	2014-04-24 23:23:47.000000000 +0200
@@ -13,6 +13,9 @@
         'NVCtrlLib.h',
         'nv_control.h',
       ],
+      'include_dirs': [
+        '<(prefix_dir)/include',
+      ],
     },
   ],
 }
