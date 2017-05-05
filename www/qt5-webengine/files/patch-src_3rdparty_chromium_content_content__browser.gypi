--- src/3rdparty/chromium/content/content_browser.gypi.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/content/content_browser.gypi
@@ -2140,6 +2140,9 @@
     ['os_bsd==1', {
       'sources/': [
         ['exclude', '^browser/gamepad/gamepad_platform_data_fetcher_linux\\.cc$'],
+        ['exclude', '^browser/zygote_host/zygote_host_impl_linux\\.cc$'],
+        ['exclude', '^zygote/zygote_linux\\.cc$'],
+        ['exclude', '^zygote/zygote_main_linux\\.cc$'],
       ],
     }],
     ['use_aura==1', {
@@ -2191,14 +2194,16 @@
         'browser/geolocation/empty_wifi_data_provider.cc',
       ],
     }],
-    ['OS == "linux" and use_dbus==1', {
-      'sources!': [
-        'browser/geolocation/empty_wifi_data_provider.cc',
-      ],
+    ['use_dbus==1', {
       'dependencies': [
         '../build/linux/system.gyp:dbus',
         '../dbus/dbus.gyp:dbus',
       ],
+    }],
+    ['OS == "linux" and use_dbus==1', {
+      'sources!': [
+        'browser/geolocation/empty_wifi_data_provider.cc',
+      ],
     }, {  # OS != "linux" or use_dbus==0
       'sources!': [
         'browser/geolocation/wifi_data_provider_linux.cc',
