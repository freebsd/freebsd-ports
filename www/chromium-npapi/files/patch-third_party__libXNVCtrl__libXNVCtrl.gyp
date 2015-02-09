--- ./third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-04-30 22:43:11.000000000 +0200
+++ ./third_party/libXNVCtrl/libXNVCtrl.gyp	2014-05-04 14:38:48.000000000 +0200
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
