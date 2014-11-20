--- third_party/libexif/libexif.gyp.orig	2014-10-10 08:54:17 UTC
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
