--- ./net/net.gyp.orig	2014-04-24 22:35:55.000000000 +0200
+++ ./net/net.gyp	2014-04-24 23:23:46.000000000 +0200
@@ -1435,9 +1435,10 @@
               }],
               ['os_bsd==1', {
                 'sources!': [
+                  'base/address_tracker_linux.cc',
                   'base/network_change_notifier_linux.cc',
                   'base/network_change_notifier_netlink_linux.cc',
-                  'proxy/proxy_config_service_linux.cc',
+#                  'proxy/proxy_config_service_linux.cc',
                 ],
               },{
                 'dependencies': [
@@ -2081,7 +2082,7 @@
         'websockets/websocket_throttle_test.cc',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'balsa',
             'epoll_server',
@@ -2359,6 +2360,11 @@
             '../testing/android/native_test.gyp:native_test_native_code',
           ]
         }],
+        [ 'os_bsd == 1', {
+          'sources!': [
+            'base/address_tracker_linux_unittest.cc',
+          ],
+        }],
       ],
       'target_conditions': [
         # These source files are excluded by default platform rules, but they
