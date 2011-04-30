--- content/content_browser.gypi.orig	2011-04-22 01:35:50.895187096 +0300
+++ content/content_browser.gypi	2011-04-22 01:43:35.628663558 +0300
@@ -324,7 +324,7 @@
         ['OS=="win"', {
           'msvs_guid': '639DB58D-32C2-435A-A711-65A12F62E442',
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus-glib',
             # For FcLangSetAdd call in render_sandbox_host_linux.cc
@@ -346,6 +346,14 @@
             ['exclude', '^browser/geolocation/wifi_data_provider_linux.h'],
           ]
         }],
+	['OS=="freebsd" or OS=="openbsd"', {
+          'sources/': [
+            ['exclude', '^browser/geolocation/wifi_data_provider_linux.cc'],
+            ['exclude', '^browser/geolocation/wifi_data_provider_linux.h'],
+            ['exclude', '^browser/geolocation/gateway_data_provider_linux.cc'],
+            ['exclude', '^browser/geolocation/gateway_data_provider_linux.h'],
+          ]
+        }],
         ['OS=="mac"', {
           'link_settings': {
             'mac_bundle_resources': [
