--- net/net.gypi.orig	2015-12-04 22:59:49.506305000 +0100
+++ net/net.gypi	2015-12-04 23:00:47.269128000 +0100
@@ -392,8 +392,8 @@
       'android/network_library.h',
       'android/traffic_stats.cc',
       'android/traffic_stats.h',
-      'base/address_tracker_linux.cc',
-      'base/address_tracker_linux.h',
+#      'base/address_tracker_linux.cc',
+#      'base/address_tracker_linux.h',
       'base/backoff_entry.cc',
       'base/backoff_entry.h',
       'base/backoff_entry_serializer.cc',
@@ -1245,7 +1245,7 @@
       'android/network_change_notifier_android_unittest.cc',
       'android/traffic_stats_unittest.cc',
       'base/address_list_unittest.cc',
-      'base/address_tracker_linux_unittest.cc',
+#      'base/address_tracker_linux_unittest.cc',
       'base/backoff_entry_serializer_unittest.cc',
       'base/backoff_entry_unittest.cc',
       'base/chunked_upload_data_stream_unittest.cc',
