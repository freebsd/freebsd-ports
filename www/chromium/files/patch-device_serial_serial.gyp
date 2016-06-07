--- device/serial/serial.gyp.orig	2016-04-08 16:02:09 UTC
+++ device/serial/serial.gyp
@@ -71,6 +71,12 @@
             },
           },
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'serial_device_enumerator_linux.cc',
+            'serial_device_enumerator_linux.h',
+          ],
+        }],
       ],
       'dependencies': [
         'device_serial_mojo',
