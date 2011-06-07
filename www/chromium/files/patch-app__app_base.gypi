--- app/app_base.gypi.orig	2011-05-06 12:02:51.000000000 +0300
+++ app/app_base.gypi	2011-06-05 20:27:30.437162962 +0300
@@ -268,7 +268,7 @@
             ['exclude', '^win/*'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
           'sources!': [
             '../ui/base/keycodes/keyboard_code_conversion_mac.mm',
             '../ui/base/keycodes/keyboard_code_conversion_mac.h',
@@ -281,7 +281,6 @@
             'link_settings': {
               'libraries': [
                 '-lX11',
-                '-ldl',
               ],
             },
           },
