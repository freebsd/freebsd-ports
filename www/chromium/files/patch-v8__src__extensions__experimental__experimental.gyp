--- v8/src/extensions/experimental/experimental.gyp.orig	2011-09-11 19:05:30.000000000 +0300
+++ v8/src/extensions/experimental/experimental.gyp	2011-09-11 19:05:46.000000000 +0300
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
