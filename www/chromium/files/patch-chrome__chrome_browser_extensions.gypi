--- chrome/chrome_browser_extensions.gypi.orig	2013-02-13 22:11:49.000000000 +0200
+++ chrome/chrome_browser_extensions.gypi	2013-02-13 23:10:09.000000000 +0200
@@ -912,6 +912,12 @@
             'browser/extensions/platform_app_launcher.h',
           ],
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'browser/extensions/api/system_info_storage/storage_info_provider_linux.cc',
+            'browser/extensions/api/system_info_storage/storage_info_provider_linux.h',
+          ],
+        }],
       ],
     },
     {
