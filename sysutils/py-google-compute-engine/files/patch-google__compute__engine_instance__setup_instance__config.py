This patch fixes the paths and disable optimization scripts used only on Linux.
The variables won't be needed to be fixed in further versions
See https://github.com/GoogleCloudPlatform/compute-image-packages/pull/440

--- google_compute_engine/instance_setup/instance_config.py.orig	2017-07-23 07:12:16 UTC
+++ google_compute_engine/instance_setup/instance_config.py
@@ -16,8 +16,8 @@
 """A library used to set up the instance's default configurations file.
 
 Note that the configurations in
-/etc/default/instance_configs.cfg.template override the values set in
-/etc/default/instance_configs.cfg. The system instance_configs.cfg may be
+%%PREFIX%%/etc/instance_configs.cfg.template override the values set in
+%%PREFIX%%/etc/instance_configs.cfg. The system instance_configs.cfg may be
 overridden during package upgrade.
 """
 
@@ -32,7 +32,7 @@ from google_compute_engine.compat import
 class InstanceConfig(config_manager.ConfigManager):
   """Creates a defaults config file for instance configuration."""
 
-  instance_config = '/etc/default/instance_configs.cfg'
+  instance_config = '%%PREFIX%%/etc/instance_configs.cfg'
   instance_config_distro = '%s.distro' % instance_config
   instance_config_template = '%s.template' % instance_config
   instance_config_script = os.path.abspath(__file__)
@@ -40,7 +40,7 @@ class InstanceConfig(config_manager.Conf
       'This file is automatically created at boot time by the %s script. Do '
       'not edit this file directly. If you need to add items to this file, '
       'create or edit %s instead and then run '
-      '/usr/bin/google_instance_setup.')
+      '%%PREFIX%%/bin/google_instance_setup.')
   instance_config_options = {
       'Accounts': {
           'deprovision_remove': 'false',
@@ -55,11 +55,11 @@ class InstanceConfig(config_manager.Conf
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
