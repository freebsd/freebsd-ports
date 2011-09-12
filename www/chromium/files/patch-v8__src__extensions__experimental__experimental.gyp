--- v8/src/extensions/experimental/experimental.gyp.orig	2011-09-03 12:13:16.000000000 +0300
+++ v8/src/extensions/experimental/experimental.gyp	2011-09-11 21:16:10.407508099 +0300
@@ -51,8 +51,14 @@
         'language-matcher.h',
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
         '../..',
       ],
       'dependencies': [
