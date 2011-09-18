--- third_party/libjpeg_turbo/libjpeg.gyp.orig	2011-09-10 20:12:17.000000000 +0300
+++ third_party/libjpeg_turbo/libjpeg.gyp	2011-09-10 20:11:50.000000000 +0300
@@ -255,6 +255,9 @@
             'defines': [
               'USE_SYSTEM_LIBJPEG',
             ],
+            'include_dirs': [
+              '<(prefix_dir)/include',
+            ],
           },
           'link_settings': {
             'libraries': [
