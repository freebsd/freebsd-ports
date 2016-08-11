--- net/net.gypi.orig	2016-05-11 19:02:24 UTC
+++ net/net.gypi
@@ -439,8 +439,8 @@
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
@@ -1310,7 +1310,7 @@
       'android/traffic_stats_unittest.cc',
       'base/address_family_unittest.cc',
       'base/address_list_unittest.cc',
-      'base/address_tracker_linux_unittest.cc',
+#      'base/address_tracker_linux_unittest.cc',
       'base/backoff_entry_serializer_unittest.cc',
       'base/backoff_entry_unittest.cc',
       'base/chunked_upload_data_stream_unittest.cc',
