--- chrome/chrome_browser.gypi.orig	2012-11-27 10:02:39.000000000 +0200
+++ chrome/chrome_browser.gypi	2012-11-29 22:30:15.798669580 +0200
@@ -2633,6 +2633,18 @@
             ['exclude', '^browser/usb/'],
           ],
         }],
+        ['os_bsd==1', {
+          'sources!': [
+            'browser/chrome_browser_main_linux.cc',
+            'browser/chrome_browser_main_linux.h',
+            'browser/media_gallery/mtp_device_delegate_impl_linux.cc',
+            'browser/media_gallery/mtp_device_delegate_impl_linux.h',
+            'browser/system_monitor/media_transfer_protocol_device_observer_linux.cc',
+            'browser/system_monitor/media_transfer_protocol_device_observer_linux.h',
+            'browser/system_monitor/removable_device_notifications_linux.cc',
+            'browser/system_monitor/removable_device_notifications_linux.h',
+          ],
+        }],
         ['OS=="mac"', {
           'sources!': [
             'browser/automation/automation_provider_list_generic.cc',
