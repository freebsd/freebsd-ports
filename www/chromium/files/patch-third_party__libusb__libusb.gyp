--- third_party/libusb/libusb.gyp.orig
+++ third_party/libusb/libusb.gyp
@@ -10,23 +10,36 @@
     {
       'target_name': 'libusb',
       'conditions': [
-        ['OS == "linux" and use_system_libusb', {
+        ['(OS == "linux" or os_bsd == 1) and use_system_libusb', {
           'type': 'none',
           'direct_dependent_settings': {
             'defines': [
               'USE_SYSTEM_LIBUSB',
             ],
-            'cflags': [
-              '<!@(pkg-config --cflags libusb-1.0)',
-            ],
-            'link_settings': {
-              'ldflags': [
-                '<!@(pkg-config --libs-only-L --libs-only-other libusb-1.0)',
-              ],
-              'libraries': [
-                '<!@(pkg-config --libs-only-l libusb-1.0)',
-              ],
-            },
+            'conditions': [
+              ['OS == "freebsd"', {
+                'link_settings': {
+                  'libraries': [
+                    '-lusb',
+                  ],
+                },
+                'defines': [
+                  'LIBUSB_CALL=',
+                ],
+              }, {
+                'cflags': [
+                  '<!@(pkg-config --cflags libusb-1.0)',
+                ],
+                'link_settings': {
+                  'ldflags': [
+                    '<!@(pkg-config --libs-only-L --libs-only-other libusb-1.0)',
+                  ],
+                  'libraries': [
+                    '<!@(pkg-config --libs-only-l libusb-1.0)',
+                  ],
+                },
+             }],
+            ], 
           },
         }, {
           'type': '<(library)',
