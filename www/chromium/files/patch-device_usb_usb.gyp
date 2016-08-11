--- device/usb/usb.gyp.orig	2016-05-25 15:01:02.000000000 -0400
+++ device/usb/usb.gyp	2016-05-30 13:54:50.903083000 -0400
@@ -117,6 +117,16 @@
             'usb_service_impl.h',
           ]
         }],
+        ['OS == "freebsd"', {
+          'dependencies!': [
+            '../../third_party/libusb/libusb.gyp:libusb',
+          ],
+          'link_settings': {
+            'ldflags': [
+              '-L/usr/lib -lusb',
+            ],
+          },
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../../chromeos/chromeos.gyp:chromeos',
