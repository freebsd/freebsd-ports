--- content/content_browser.gypi.orig	2011-11-01 10:42:35.000000000 +0200
+++ content/content_browser.gypi	2011-11-21 21:36:39.000000000 +0200
@@ -625,6 +625,12 @@
         '../views/views.gyp:views',
       ],
     }],
+    ['OS=="freebsd" or OS=="openbsd"', {
+      'sources/': [
+        ['exclude', '^browser/geolocation/wifi_data_provider_linux.cc'],
+        ['exclude', '^browser/geolocation/wifi_data_provider_linux.h'],
+      ]
+    }],
     ['OS=="mac"', {
       'sources!': [
         'browser/power_save_blocker_stub.cc',
