--- device/hid/hid.gyp.orig	2016-05-11 19:02:22 UTC
+++ device/hid/hid.gyp
@@ -64,6 +64,18 @@
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
     {
