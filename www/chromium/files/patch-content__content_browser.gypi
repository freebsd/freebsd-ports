--- content/content_browser.gypi.orig	2012-10-31 21:01:37.000000000 +0200
+++ content/content_browser.gypi	2012-11-07 13:18:40.000000000 +0200
@@ -995,8 +995,17 @@
     }],
     ['os_bsd==1', {
       'sources/': [
+        ['exclude', 'public/browser/zygote_host_linux\\.h$'],
+        ['exclude', 'browser/zygote_host/zygote_host_impl_linux\\.cc$'],
+        ['exclude', 'browser/zygote_host/zygote_host_impl_linux\\.h$'],
+        ['exclude', 'zygote/zygote_linux\\.cc$'],
+        ['exclude', 'zygote/zygote_linux\\.h$'],
+        ['exclude', 'zygote/zygote_main_linux\\.cc$'],
+        ['exclude', '^browser/device_monitor_linux\\.cc$'],
+        ['exclude', '^browser/download/file_metadata_linux\\.cc$'],
         ['exclude', '^browser/gamepad/gamepad_platform_data_fetcher_linux\\.cc$'],
         ['exclude', '^browser/geolocation/wifi_data_provider_linux\\.cc$'],
+        ['exclude', '^browser/udev_linux\\.cc$'],
       ],
     }],
     ['use_aura==1', {
