--- chrome/chrome_browser.gypi.orig	2012-10-31 21:02:48.000000000 +0200
+++ chrome/chrome_browser.gypi	2012-11-07 16:06:11.000000000 +0200
@@ -2531,6 +2531,14 @@
             ['exclude', '^browser/usb/'],
           ],
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'browser/media_gallery/media_device_notifications_linux.cc',
+            'browser/media_gallery/media_device_notifications_linux.h',
+            'browser/system_monitor/removable_device_notifications_linux.cc',
+            'browser/system_monitor/removable_device_notifications_linux.h'
+          ],
+        }],
         ['OS=="mac"', {
           'sources!': [
             'browser/automation/automation_provider_list_generic.cc',
