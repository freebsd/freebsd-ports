--- net/net.gyp.orig	2013-09-20 05:36:19.000000000 +0300
+++ net/net.gyp	2013-09-23 20:45:35.000000000 +0300
@@ -1283,9 +1283,10 @@
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
@@ -1865,7 +1866,7 @@
         'websockets/websocket_throttle_unittest.cc',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'quic_library',
             'flip_in_mem_edsm_server_library',
@@ -2140,6 +2141,11 @@
             'cert/x509_cert_types_unittest.cc',
           ],
         }],
+        [ 'os_bsd == 1', {
+          'sources!': [
+            'base/address_tracker_linux_unittest.cc',
+          ],
+        }],
       ],
     },
     {
