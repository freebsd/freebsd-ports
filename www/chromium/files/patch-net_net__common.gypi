--- net/net_common.gypi.orig	2016-05-11 19:02:24 UTC
+++ net/net_common.gypi
@@ -242,9 +242,10 @@
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
