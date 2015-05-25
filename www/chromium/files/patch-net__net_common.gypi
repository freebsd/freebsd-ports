--- net/net_common.gypi.orig	2015-05-20 16:10:47.668198000 -0400
+++ net/net_common.gypi	2015-05-20 16:10:38.213855000 -0400
@@ -246,9 +246,10 @@
         'conditions': [
           ['os_bsd==1', {
             'sources!': [
+              'base/address_tracker_linux.cc',
               'base/network_change_notifier_linux.cc',
               'base/network_change_notifier_netlink_linux.cc',
-              'proxy/proxy_config_service_linux.cc',
+#              'proxy/proxy_config_service_linux.cc',
             ],
           },{
             'dependencies': [
