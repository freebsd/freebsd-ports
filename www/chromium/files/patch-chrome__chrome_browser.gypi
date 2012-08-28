--- chrome/chrome_browser.gypi.orig	2012-07-25 22:44:49.000000000 +0300
+++ chrome/chrome_browser.gypi	2012-07-25 22:45:48.000000000 +0300
@@ -4769,6 +4769,12 @@
             ['exclude', '^browser/usb/'],
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
