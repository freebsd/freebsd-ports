--- ./third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-08-20 21:03:03.000000000 +0200
+++ ./third_party/libXNVCtrl/libXNVCtrl.gyp	2014-08-22 15:06:26.000000000 +0200
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
