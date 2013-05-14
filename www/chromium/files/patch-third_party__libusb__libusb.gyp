--- third_party/libusb/libusb.gyp.orig	2013-04-30 10:21:05.000000000 +0300
+++ third_party/libusb/libusb.gyp	2013-05-08 20:58:00.000000000 +0300
@@ -10,31 +10,43 @@
     {
       'target_name': 'libusb',
       'conditions': [
-        ['OS == "linux" and use_system_libusb==1', {
-          'type': 'none',
-          'variables': {
-            'headers_root_path': 'src/libusb',
-            'header_filenames': [
-              'libusb.h',
-            ],
-          },
-          'includes': [
-            '../../build/shim_headers.gypi',
-          ],
+        ['(OS == "linux" or os_bsd == 1) and use_system_libusb==1', {
+          'type': 'none',          
           'direct_dependent_settings': {
-            'cflags': [
-              '<!@(pkg-config --cflags libusb-1.0)',
+            'conditions': [
+              ['OS == "freebsd"', {
+                'direct_dependent_settings': {
+                  'link_settings': {
+                    'libraries': [
+                      '-lusb',
+                    ],
+                  },
+                },
+              }, {
+                'variables': {
+                  'headers_root_path': 'src/libusb',
+                  'header_filenames': [
+                    'libusb.h',
+                  ],
+                },
+                'includes': [
+                  '../../build/shim_headers.gypi',
+                ],
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
+              }],
             ],
-            'link_settings': {
-              'ldflags': [
-                '<!@(pkg-config --libs-only-L --libs-only-other libusb-1.0)',
-              ],
-              'libraries': [
-                '<!@(pkg-config --libs-only-l libusb-1.0)',
-              ],
-            },
-          },
-        }, {
+          },         
+        }, {          
           'type': 'static_library',
           'sources': [
             'src/libusb/core.c',
