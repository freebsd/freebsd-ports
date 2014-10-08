--- third_party/libXNVCtrl/libXNVCtrl.gyp.orig	2014-10-02 17:19:02 UTC
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
