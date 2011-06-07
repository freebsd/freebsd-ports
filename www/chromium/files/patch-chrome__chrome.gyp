--- chrome/chrome.gyp.orig	2011-05-06 12:03:42.000000000 +0300
+++ chrome/chrome.gyp	2011-06-04 00:41:46.403404482 +0300
@@ -72,6 +72,10 @@
           }],
         ],
       },],
+      ['OS=="freebsd" or OS=="openbsd"', {
+        'platform_locale_settings_grd':
+            'app/resources/locale_settings_linux.grd',
+      },],
       ['OS=="mac"', {
         'tweak_info_plist_path': 'tools/build/mac/tweak_info_plist',
         'nacl_defines': [
@@ -419,7 +423,7 @@
         '..',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -769,7 +773,7 @@
             'service/cloud_print/print_system_win.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
