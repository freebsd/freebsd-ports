--- content/content_browser.gypi.orig	2016-05-11 19:02:21 UTC
+++ content/content_browser.gypi
@@ -843,6 +843,8 @@
       'browser/geolocation/wifi_data_provider_common_win.cc',
       'browser/geolocation/wifi_data_provider_common_win.h',
       'browser/geolocation/wifi_data_provider_corewlan_mac.mm',
+      'browser/geolocation/wifi_data_provider_freebsd.cc',
+      'browser/geolocation/wifi_data_provider_freebsd.h',
       'browser/geolocation/wifi_data_provider_linux.cc',
       'browser/geolocation/wifi_data_provider_linux.h',
       'browser/geolocation/wifi_data_provider_mac.cc',
@@ -1988,7 +1990,7 @@
         },
       },
     }],
-    ['OS=="linux" and chromeos==0 and use_x11==1', {
+    ['(os_bsd==1 or OS=="linux") and chromeos==0 and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:atk',
         '../build/linux/system.gyp:gconf',
@@ -2014,7 +2016,7 @@
         'browser/gamepad/gamepad_platform_data_fetcher_linux.cc',
       ],
     }],
-    ['OS=="linux" and use_aura==1', {
+    ['(os_bsd==1 or OS=="linux") and use_aura==1', {
       'dependencies': [
         '../build/linux/system.gyp:fontconfig',
       ],
@@ -2109,8 +2111,24 @@
       ],
     }],
     ['os_bsd==1', {
-      'sources/': [
-        ['exclude', '^browser/gamepad/gamepad_platform_data_fetcher_linux\\.cc$'],
+      'sources!': [
+        'public/browser/zygote_host_linux.h',
+        'browser/zygote_host/zygote_communication_linux.cc',
+        'browser/zygote_host/zygote_communication_linux.h',
+        'browser/zygote_host/zygote_handle_linux.cc',
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
+      ],
+      'dependencies': [
+        '../build/linux/system.gyp:dbus',
       ],
     }],
     ['use_aura==1', {
@@ -2159,10 +2177,7 @@
         'browser/geolocation/empty_wifi_data_provider.cc',
       ],
     }],
-    ['OS == "linux" and use_dbus==1', {
-      'sources!': [
-        'browser/geolocation/empty_wifi_data_provider.cc',
-      ],
+    ['(OS == "linux" or os_bsd==1) and use_dbus==1', {
       'dependencies': [
         '../build/linux/system.gyp:dbus',
         '../dbus/dbus.gyp:dbus',
@@ -2178,7 +2193,7 @@
         'browser/media/cdm/browser_cdm_manager.h',
       ],
     }],
-    ['OS == "linux"', {
+    ['(os_bsd==1 or OS == "linux")', {
       'dependencies': [
         '../third_party/boringssl/boringssl.gyp:boringssl',
       ],
