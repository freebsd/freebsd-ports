--- net/net.gypi.orig	2015-10-21 18:00:38.000000000 -0400
+++ net/net.gypi	2015-10-23 12:58:44.791781000 -0400
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
+      #'base/address_tracker_linux_unittest.cc',
       'base/backoff_entry_serializer_unittest.cc',
       'base/backoff_entry_unittest.cc',
       'base/chunked_upload_data_stream_unittest.cc',
