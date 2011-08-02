--- content/content_browser.gypi.orig	2011-06-24 11:30:33.000000000 +0300
+++ content/content_browser.gypi	2011-06-26 21:57:25.042787140 +0300
@@ -393,6 +393,14 @@
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
