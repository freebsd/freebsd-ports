--- third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-10-10 08:54:17 UTC
+++ third_party/libXNVCtrl/libXNVCtrl.gyp
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
