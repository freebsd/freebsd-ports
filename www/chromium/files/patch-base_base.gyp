--- ./base/base.gyp.orig	2016-07-22 00:06:49.000000000 -0400
+++ ./base/base.gyp	2016-08-05 08:28:39.441243000 -0400
@@ -114,7 +114,7 @@
           ],
           'link_settings': {
             'libraries': [
-              '-L/usr/local/lib -lexecinfo',
+              '-L/usr/local/lib -lexecinfo -lkvm',
             ],
           },
         }],
@@ -286,13 +286,13 @@
           ],
         }],
         ['icu_use_data_file_flag==1', {
-          'defines': ['ICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_FILE'],
+          'defines': ['ICU_UTIL_DATA_IMPL=0'],
         }, { # else icu_use_data_file_flag !=1
           'conditions': [
             ['OS=="win"', {
-              'defines': ['ICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_SHARED'],
+              'defines': ['ICU_UTIL_DATA_IMPL=1'],
             }, {
-              'defines': ['ICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_STATIC'],
+              'defines': ['ICU_UTIL_DATA_IMPL=2'],
             }],
           ],
         }],
@@ -773,6 +773,11 @@
             'sync_socket_unittest.cc',
           ],
         }],
+        ['OS == "freebsd"', {
+          'sources!': [
+            'debug/proc_maps_linux_unittest.cc',
+          ],
+        }],
       ],  # target_conditions
     },
     {
