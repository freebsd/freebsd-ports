--- ./components/usb_service.gypi.orig	2014-08-20 21:02:56.000000000 +0200
+++ ./components/usb_service.gypi	2014-08-22 15:06:25.000000000 +0200
@@ -41,6 +41,11 @@
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
