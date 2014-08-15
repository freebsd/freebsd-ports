--- ./components/usb_service.gypi.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/usb_service.gypi	2014-08-13 09:56:57.000000000 +0200
@@ -37,6 +37,11 @@
         'dependencies': [
           '../build/linux/system.gyp:udev',
         ],
+      }],
+      ['OS == "freebsd"', {
+        'dependencies!': [
+          '../third_party/libusb/libusb.gyp:libusb',
+        ],
       }]
     ]
   }],
