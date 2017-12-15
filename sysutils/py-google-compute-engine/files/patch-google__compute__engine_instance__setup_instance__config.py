--- google_compute_engine/instance_setup/instance_config.py.orig	2017-09-29 00:21:28 UTC
+++ google_compute_engine/instance_setup/instance_config.py
@@ -72,11 +72,11 @@ class InstanceConfig(config_manager.Conf
           'instance_id': '0',
       },
       'InstanceSetup': {
-          'optimize_local_ssd': 'true',
+          'optimize_local_ssd': 'false',
           'network_enabled': 'true',
           'set_boto_config': 'true',
           'set_host_keys': 'true',
-          'set_multiqueue': 'true',
+          'set_multiqueue': 'false',
       },
       'IpForwarding': {
           'ethernet_proto_id': '66',
