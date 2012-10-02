--- net/net.gyp.orig	2012-09-25 16:01:38.000000000 +0300
+++ net/net.gyp	2012-10-01 20:04:49.000000000 +0300
@@ -943,9 +943,10 @@
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
