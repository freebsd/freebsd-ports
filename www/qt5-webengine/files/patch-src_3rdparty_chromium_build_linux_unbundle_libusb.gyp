--- src/3rdparty/chromium/build/linux/unbundle/libusb.gyp.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/build/linux/unbundle/libusb.gyp
@@ -18,14 +18,14 @@
       ],
       'direct_dependent_settings': {
         'cflags': [
-          '<!@(pkg-config --cflags libusb-1.0)',
+          '',
         ],
         'link_settings': {
           'ldflags': [
-            '<!@(pkg-config --libs-only-L --libs-only-other libusb-1.0)',
+            '-lusb',
           ],
           'libraries': [
-            '<!@(pkg-config --libs-only-l libusb-1.0)',
+            '-lusb',
           ],
         },
       },
