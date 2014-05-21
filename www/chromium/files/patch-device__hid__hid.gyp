--- ./device/hid/hid.gyp.orig	2014-04-30 22:43:21.000000000 +0200
+++ ./device/hid/hid.gyp	2014-05-04 14:38:48.000000000 +0200
@@ -23,8 +23,8 @@
       'sources': [
         'hid_connection.cc',
         'hid_connection.h',
-        'hid_connection_linux.cc',
-        'hid_connection_linux.h',
+        #'hid_connection_linux.cc',
+        #'hid_connection_linux.h',
         'hid_connection_mac.cc',
         'hid_connection_mac.h',
         'hid_connection_win.cc',
@@ -33,8 +33,8 @@
         'hid_device_info.h',
         'hid_service.cc',
         'hid_service.h',
-        'hid_service_linux.cc',
-        'hid_service_linux.h',
+        #'hid_service_linux.cc',
+        #'hid_service_linux.h',
         'hid_service_mac.cc',
         'hid_service_mac.h',
         'hid_service_win.cc',
