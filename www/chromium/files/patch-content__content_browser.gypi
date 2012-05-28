--- content/content_browser.gypi.orig	2012-04-29 23:50:13.000000000 +0300
+++ content/content_browser.gypi	2012-04-29 23:49:20.000000000 +0300
@@ -839,6 +839,7 @@
     }],
     ['os_bsd==1', {
       'sources/': [
+        ['exclude', '^browser/media_device_notifications_linux\\.cc$'],
         ['exclude', '^browser/gamepad/platform_data_fetcher_linux\\.cc$'],
         ['exclude', '^browser/geolocation/wifi_data_provider_linux\\.cc$'],
       ],
