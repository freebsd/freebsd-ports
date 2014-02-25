--- content/content_browser.gypi.orig	2014-02-20 21:28:25.000000000 +0100
+++ content/content_browser.gypi	2014-02-24 22:56:37.000000000 +0100
@@ -586,6 +586,8 @@
     'browser/geolocation/wifi_data_provider_common_win.cc',
     'browser/geolocation/wifi_data_provider_common_win.h',
     'browser/geolocation/wifi_data_provider_corewlan_mac.mm',
+    'browser/geolocation/wifi_data_provider_freebsd.cc',
+    'browser/geolocation/wifi_data_provider_freebsd.h',
     'browser/geolocation/wifi_data_provider_linux.cc',
     'browser/geolocation/wifi_data_provider_linux.h',
     'browser/geolocation/wifi_data_provider_mac.cc',
@@ -1543,8 +1545,18 @@
       ],
     }],
     ['os_bsd==1', {
-      'sources/': [
-        ['exclude', '^browser/gamepad/gamepad_platform_data_fetcher_linux\\.cc$'],
+      'sources!': [
+        'public/browser/zygote_host_linux.h',
+        'browser/zygote_host/zygote_host_impl_linux.cc',
+        'browser/zygote_host/zygote_host_impl_linux.h',
+        'zygote/zygote_linux.cc',
+        'zygote/zygote_linux.h',
+        'zygote/zygote_main_linux.cc',
+        'browser/device_monitor_linux.cc',
+        'browser/download/file_metadata_linux.cc',
+        'browser/gamepad/gamepad_platform_data_fetcher_linux.cc',
+        'browser/geolocation/wifi_data_provider_linux.cc',
+        'browser/udev_linux.cc',
       ],
     }],
     ['use_aura!=1 and OS!="win"', {
