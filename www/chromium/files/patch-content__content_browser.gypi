--- ./content/content_browser.gypi.orig	2014-08-12 21:01:27.000000000 +0200
+++ ./content/content_browser.gypi	2014-08-13 09:56:57.000000000 +0200
@@ -631,6 +631,8 @@
     'browser/geolocation/wifi_data_provider_common_win.cc',
     'browser/geolocation/wifi_data_provider_common_win.h',
     'browser/geolocation/wifi_data_provider_corewlan_mac.mm',
+    'browser/geolocation/wifi_data_provider_freebsd.cc',
+    'browser/geolocation/wifi_data_provider_freebsd.h',
     'browser/geolocation/wifi_data_provider_linux.cc',
     'browser/geolocation/wifi_data_provider_linux.h',
     'browser/geolocation/wifi_data_provider_mac.cc',
@@ -1652,8 +1654,18 @@
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
     ['use_aura==1', {
@@ -1717,7 +1729,7 @@
         'browser/geolocation/empty_wifi_data_provider.cc',
       ],
     }],
-    ['OS == "linux" and use_dbus==1', {
+    ['(OS == "linux" or os_bsd==1) and use_dbus==1', {
       'sources!': [
         'browser/geolocation/empty_wifi_data_provider.cc',
       ],
