--- net/net.gyp.orig	2014-10-02 17:39:47 UTC
+++ net/net.gyp
@@ -322,9 +322,10 @@
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
@@ -556,7 +557,7 @@
         '<@(net_test_sources)',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'epoll_server',
             'flip_in_mem_edsm_server_base',
@@ -1028,6 +1029,11 @@
               'test/cert_test_util_nss.cc',
             ],
         }],
+        [ 'os_bsd == 1', {
+          'sources!': [
+            'base/address_tracker_linux_unittest.cc',
+          ],
+        }],
       ],
       # TODO(jschuh): crbug.com/167187 fix size_t to int truncations.
       'msvs_disabled_warnings': [4267, ],
