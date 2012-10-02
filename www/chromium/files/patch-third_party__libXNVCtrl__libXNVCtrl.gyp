--- third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2012-10-02 20:32:18.000000000 +0300
+++ third_party/libXNVCtrl/libXNVCtrl.gyp	2012-10-02 20:32:24.000000000 +0300
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
