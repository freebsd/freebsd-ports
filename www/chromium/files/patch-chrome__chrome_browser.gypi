--- chrome/chrome_browser.gypi.orig	2013-02-05 10:03:06.000000000 +0200
+++ chrome/chrome_browser.gypi	2013-02-13 22:38:19.000000000 +0200
@@ -2781,6 +2781,19 @@
             ['exclude', '^browser/usb/'],
           ],
         }],
+        ['os_bsd==1', {
+          'sources/': [
+            ['exclude', '^browser/chrome_browser_main_linux.cc'],
+            ['exclude', '^browser/chrome_browser_main_linux.h'],
+            ['exclude', '^browser/media_gallery/linux/'],
+            ['exclude', '^browser/system_monitor/media_transfer_protocol_device_observer_linux.cc'],
+            ['exclude', '^browser/system_monitor/media_transfer_protocol_device_observer_linux.h'],
+            ['exclude', '^browser/system_monitor/removable_device_notifications_linux.cc'],
+            ['exclude', '^browser/system_monitor/removable_device_notifications_linux.h'],
+            ['exclude', '^browser/system_monitor/udev_util_linux.cc'],
+            ['exclude', '^browser/system_monitor/udev_util_linux.h'],
+          ],
+        }],
         ['OS=="mac"', {
           'sources!': [
             'browser/automation/automation_provider_list_generic.cc',
