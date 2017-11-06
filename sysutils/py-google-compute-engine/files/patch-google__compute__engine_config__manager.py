This patch won't be necessary anymore in further versions.
See https://github.com/GoogleCloudPlatform/compute-image-packages/pull/440

--- google_compute_engine/config_manager.py.orig	2017-07-23 07:12:16 UTC
+++ google_compute_engine/config_manager.py
@@ -21,7 +21,7 @@ import textwrap
 from google_compute_engine import file_utils
 from google_compute_engine.compat import parser
 
-CONFIG = '/etc/default/instance_configs.cfg'
+CONFIG = '%%PREFIX%%/etc/instance_configs.cfg'
 
 
 class ConfigManager(object):
@@ -101,7 +101,7 @@ class ConfigManager(object):
     """
     config_file = config_file or self.config_file
     config_name = os.path.splitext(os.path.basename(config_file))[0]
-    config_lock = '/var/lock/google_%s.lock' % config_name
+    config_lock = '/var/spool/lock/google_%s.lock' % config_name
     with file_utils.LockFile(config_lock):
       with open(config_file, 'w') as config_fp:
         if self.config_header:
