--- net/net.gyp.orig	2013-08-19 02:54:02.000000000 +0300
+++ net/net.gyp	2013-09-01 00:26:02.000000000 +0300
@@ -1259,9 +1259,10 @@
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
@@ -2076,6 +2077,11 @@
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
