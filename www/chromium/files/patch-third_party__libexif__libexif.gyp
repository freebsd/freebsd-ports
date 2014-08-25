--- ./third_party/libexif/libexif.gyp.orig	2014-08-20 21:03:07.000000000 +0200
+++ ./third_party/libexif/libexif.gyp	2014-08-21 23:18:11.000000000 +0200
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
