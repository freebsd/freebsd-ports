--- ./third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-08-12 21:02:42.000000000 +0200
+++ ./third_party/libXNVCtrl/libXNVCtrl.gyp	2014-08-13 09:56:58.000000000 +0200
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
