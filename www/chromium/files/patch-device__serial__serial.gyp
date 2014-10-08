--- device/serial/serial.gyp.orig	2014-10-02 17:39:47 UTC
+++ device/serial/serial.gyp
@@ -32,6 +32,12 @@
             '../../build/linux/system.gyp:udev',
           ],
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
