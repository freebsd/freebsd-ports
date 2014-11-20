--- device/usb/usb.gyp.orig	2014-10-10 08:54:15 UTC
+++ device/usb/usb.gyp
@@ -65,6 +65,11 @@
             '../../build/linux/system.gyp:udev',
           ],
         }],
+        ['OS == "freebsd"', {
+          'dependencies!': [
+            '../../third_party/libusb/libusb.gyp:libusb',
+          ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../../chromeos/chromeos.gyp:chromeos',
