--- chrome/chrome_browser.gypi.orig	2012-06-13 10:02:23.000000000 +0300
+++ chrome/chrome_browser.gypi	2012-06-14 22:36:41.000000000 +0300
@@ -4541,11 +4541,17 @@
             ['exclude', '^browser/usb/'],
           ],
         }],
-        ['OS!="android"', {
+        ['OS!="android" and OS!="freebsd"', {
           'dependencies': [
             '../third_party/libusb/libusb.gyp:libusb',
           ],
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'browser/media_gallery/media_device_notifications_linux.cc',
+            'browser/media_gallery/media_device_notifications_linux.h',
+          ],
+        }],
         ['OS=="mac"', {
           'sources!': [
             'browser/automation/automation_provider_list_generic.cc',
