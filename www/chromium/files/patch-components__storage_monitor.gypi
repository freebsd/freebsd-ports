--- components/storage_monitor.gypi.orig	2014-10-10 08:54:14 UTC
+++ components/storage_monitor.gypi
@@ -50,6 +50,26 @@
         'storage_monitor/volume_mount_watcher_win.h',
       ],
       'conditions': [
+        ['os_bsd == 1', {
+          'sources!': [
+            'storage_monitor/media_transfer_protocol_device_observer_linux.cc',
+            'storage_monitor/media_transfer_protocol_device_observer_linux.h',
+            'storage_monitor/test_media_transfer_protocol_manager_linux.cc',
+            'storage_monitor/test_media_transfer_protocol_manager_linux.h',
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
