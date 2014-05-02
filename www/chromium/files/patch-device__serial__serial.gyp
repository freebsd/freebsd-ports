--- ./device/serial/serial.gyp.orig	2014-04-24 22:35:32.000000000 +0200
+++ ./device/serial/serial.gyp	2014-04-24 23:23:45.000000000 +0200
@@ -23,8 +23,8 @@
       'sources': [
         'serial_device_enumerator.cc',
         'serial_device_enumerator.h',
-        'serial_device_enumerator_linux.cc',
-        'serial_device_enumerator_linux.h',
+        #'serial_device_enumerator_linux.cc',
+        #'serial_device_enumerator_linux.h',
         'serial_device_enumerator_mac.cc',
         'serial_device_enumerator_mac.h',
         'serial_device_enumerator_win.cc',
