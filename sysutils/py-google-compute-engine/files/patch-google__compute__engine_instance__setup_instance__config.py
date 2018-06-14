--- google_compute_engine/instance_setup/instance_config.py.orig	2018-06-11 23:51:09 UTC
+++ google_compute_engine/instance_setup/instance_config.py
@@ -74,11 +74,11 @@ class InstanceConfig(config_manager.Conf
       },
       'InstanceSetup': {
           'host_key_types': 'ecdsa,ed25519,rsa',
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
