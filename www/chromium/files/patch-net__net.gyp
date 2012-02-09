--- net/net.gyp.orig	2012-01-30 23:30:30.000000000 +0200
+++ net/net.gyp	2012-01-30 23:30:57.000000000 +0200
@@ -853,7 +853,7 @@
                 'sources!': [
                   'base/network_change_notifier_linux.cc',
                   'base/network_change_notifier_netlink_linux.cc',
-                  'proxy/proxy_config_service_linux.cc',
+#                  'proxy/proxy_config_service_linux.cc',
                 ],
               },{
                 'dependencies': [
