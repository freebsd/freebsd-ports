--- chrome/chrome_browser_extensions.gypi.orig	2013-05-08 00:59:31.000000000 +0300
+++ chrome/chrome_browser_extensions.gypi	2013-05-08 01:23:36.000000000 +0300
@@ -409,6 +409,7 @@
         'browser/extensions/api/system_info_storage/storage_info_provider.cc',
         'browser/extensions/api/system_info_storage/storage_info_provider.h',
         'browser/extensions/api/system_info_storage/storage_info_provider_android.cc',
+        'browser/extensions/api/system_info_storage/storage_info_provider_bsd.cc',
         'browser/extensions/api/system_info_storage/storage_info_provider_linux.cc',
         'browser/extensions/api/system_info_storage/storage_info_provider_mac.cc',
         'browser/extensions/api/system_info_storage/storage_info_provider_win.cc',
@@ -930,6 +931,14 @@
             'browser/extensions/platform_app_launcher.h',
           ],
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'browser/extensions/api/system_info_storage/storage_info_provider_linux.cc',
+          ],
+          'sources': [
+            'browser/extensions/api/system_info_storage/storage_info_provider_bsd.cc',
+          ],
+        }],
       ],
     },
   ],
