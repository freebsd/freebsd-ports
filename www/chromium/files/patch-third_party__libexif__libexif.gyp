--- third_party/libexif/libexif.gyp.orig	2014-09-04 00:04:19 UTC
+++ third_party/libexif/libexif.gyp
@@ -5,9 +5,9 @@
 {
   'variables': {
     'conditions': [
-      ['OS == "linux" and chromeos==0', {
+      ['(OS == "linux" or OS == "freebsd") and chromeos==0', {
         'use_system_libexif%': 1,
-      }, {  # OS != "linux" and chromeos==0
+      }, {  # (OS != "linux" and OS != "freebsd") or chromeos==0
         'use_system_libexif%': 0,
       }],
     ],
