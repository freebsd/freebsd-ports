--- ./net/net.gypi.orig	2014-08-20 21:02:28.000000000 +0200
+++ ./net/net.gypi	2014-08-22 15:06:26.000000000 +0200
@@ -171,8 +171,8 @@
       'android/network_change_notifier_factory_android.h',
       'android/network_library.cc',
       'android/network_library.h',
-      'base/address_tracker_linux.cc',
-      'base/address_tracker_linux.h',
+      #'base/address_tracker_linux.cc',
+      #'base/address_tracker_linux.h',
       'base/backoff_entry.cc',
       'base/backoff_entry.h',
       'base/bandwidth_metrics.cc',
@@ -1221,7 +1221,7 @@
       'android/keystore_unittest.cc',
       'android/network_change_notifier_android_unittest.cc',
       'base/address_list_unittest.cc',
-      'base/address_tracker_linux_unittest.cc',
+      #'base/address_tracker_linux_unittest.cc',
       'base/backoff_entry_unittest.cc',
       'base/data_url_unittest.cc',
       'base/directory_lister_unittest.cc',
