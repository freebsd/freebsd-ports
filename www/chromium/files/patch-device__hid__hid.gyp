--- device/hid/hid.gyp.orig	2014-10-10 08:54:15 UTC
+++ device/hid/hid.gyp
@@ -63,6 +63,18 @@
             'input_service_linux.h',
           ],
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'device_monitor_linux.cc',
+            'device_monitor_linux.h',
+            'hid_connection_linux.cc',
+            'hid_connection_linux.h',
+            'hid_service_linux.cc',
+            'hid_service_linux.h',
+            'input_service_linux.cc',
+            'input_service_linux.h',
+          ],
+        }],
       ],
     },
   ],
