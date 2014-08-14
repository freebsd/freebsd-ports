--- ./components/storage_monitor.gypi.orig	2014-08-12 21:02:37.000000000 +0200
+++ ./components/storage_monitor.gypi	2014-08-13 09:56:57.000000000 +0200
@@ -49,6 +49,24 @@
         'storage_monitor/volume_mount_watcher_win.h',
       ],
       'conditions': [
+        ['os_bsd == 1', {
+          'sources!': [
+            'storage_monitor/media_transfer_protocol_device_observer_linux.cc',
+            'storage_monitor/media_transfer_protocol_device_observer_linux.h',
+            'storage_monitor/mtab_watcher_linux.cc',
+            'storage_monitor/mtab_watcher_linux.h',
+            'storage_monitor/storage_monitor_linux.cc',
+            'storage_monitor/storage_monitor_linux.h',
+            'storage_monitor/udev_util_linux.cc',
+            'storage_monitor/udev_util_linux.h',
+          ],
+        }],
+        ['OS == "freebsd"', {
+          'sources': [
+            'storage_monitor/storage_monitor_freebsd.cc',
+            'storage_monitor/storage_monitor_freebsd.h',
+          ],
+        }],
         ['OS == "mac"', {
           'link_settings': {
             'libraries': [
