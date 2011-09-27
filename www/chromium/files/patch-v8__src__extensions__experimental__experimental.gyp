--- v8/src/extensions/experimental/experimental.gyp.orig	2011-09-14 11:19:51.000000000 +0300
+++ v8/src/extensions/experimental/experimental.gyp	2011-09-26 02:10:36.000000000 +0300
@@ -56,8 +56,14 @@
         'number-format.h',
         '<(SHARED_INTERMEDIATE_DIR)/i18n-js.cc',
       ],
+      'conditions': [
+        ['use_system_icu == 0', {
+          'include_dirs': [
+            '<(icu_src_dir)/public/common',
+          ],
+        }],
+      ],
       'include_dirs': [
-        '<(icu_src_dir)/public/common',
         # v8/ is root for all includes.
         '../../..'
       ],
@@ -71,6 +77,13 @@
         'include_dirs': [
           '../../..'
         ],
+        'conditions': [
+          ['OS == "freebsd"', {
+            'include_dirs!': [
+              '<(prefix_dir)/include',
+            ],
+          }],
+        ],
       },
     },
     {
