--- ./net/net.gyp.orig	2014-08-20 21:02:28.000000000 +0200
+++ ./net/net.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -317,9 +317,10 @@
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
@@ -551,7 +552,7 @@
         '<@(net_test_sources)',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'epoll_server',
             'flip_in_mem_edsm_server_base',
@@ -1016,6 +1017,11 @@
               'dns/mock_mdns_socket_factory.h'
             ]
         }],
+        [ 'os_bsd == 1', {
+          'sources!': [
+            'base/address_tracker_linux_unittest.cc',
+          ],
+        }],
       ],
       # TODO(jschuh): crbug.com/167187 fix size_t to int truncations.
       'msvs_disabled_warnings': [4267, ],
