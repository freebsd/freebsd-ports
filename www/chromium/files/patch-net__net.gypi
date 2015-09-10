--- net/net.gypi.orig	2015-07-15 16:30:05.000000000 -0400
+++ net/net.gypi	2015-07-22 07:53:36.298350000 -0400
@@ -196,8 +196,8 @@
       'android/network_change_notifier_factory_android.h',
       'android/network_library.cc',
       'android/network_library.h',
-      'base/address_tracker_linux.cc',
-      'base/address_tracker_linux.h',
+      #'base/address_tracker_linux.cc',
+      #'base/address_tracker_linux.h',
       'base/backoff_entry.cc',
       'base/backoff_entry.h',
       'base/backoff_entry_serializer.cc',
@@ -1278,7 +1278,7 @@
       'android/keystore_unittest.cc',
       'android/network_change_notifier_android_unittest.cc',
       'base/address_list_unittest.cc',
-      'base/address_tracker_linux_unittest.cc',
+      #'base/address_tracker_linux_unittest.cc',
       'base/backoff_entry_serializer_unittest.cc',
       'base/backoff_entry_unittest.cc',
       'base/chunked_upload_data_stream_unittest.cc',
