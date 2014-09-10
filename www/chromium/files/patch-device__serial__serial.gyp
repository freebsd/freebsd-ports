--- ./device/serial/serial.gyp.orig	2014-08-20 21:03:08.000000000 +0200
+++ ./device/serial/serial.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -20,6 +20,12 @@
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
       'variables': {
         'mojom_base_output_dir': 'device/serial',
