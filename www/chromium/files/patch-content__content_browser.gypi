--- content/content_browser.gypi.orig	2012-10-01 20:09:41.000000000 +0300
+++ content/content_browser.gypi	2012-10-01 20:20:01.000000000 +0300
@@ -950,9 +950,12 @@
       ],
     }],
     ['os_bsd==1', {
-      'sources/': [
+      'sources/': [        
+        ['exclude', '^browser/device_monitor_linux\\.cc$'],
+        ['exclude', '^browser/download/file_metadata_linux\\.cc$'],
         ['exclude', '^browser/gamepad/platform_data_fetcher_linux\\.cc$'],
         ['exclude', '^browser/geolocation/wifi_data_provider_linux\\.cc$'],
+        ['exclude', '^browser/udev_linux\\.cc$'],
       ],
     }],
     ['use_aura==1', {
