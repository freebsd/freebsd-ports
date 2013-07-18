--- third_party/libusb/libusb.gyp.orig	2013-06-19 01:35:24.000000000 +0000
+++ third_party/libusb/libusb.gyp	2013-06-24 21:04:31.000000000 +0000
@@ -67,6 +67,19 @@
             '_GNU_SOURCE=1',
           ],
         }],
+        ['OS == "freebsd"', {
+          'type': 'none',
+          'sources/': [
+            ['exclude', '^src/libusb/'],
+          ],
+          'direct_dependent_settings': {
+            'link_settings': {
+              'libraries': [
+                '-lusb',
+              ],
+            },
+          },
+        }],
       ],
     },
   ],
