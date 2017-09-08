This patch won't be necessary anymore in further versions.
See https://github.com/GoogleCloudPlatform/compute-image-packages/pull/440

--- google_compute_engine/boto/boto_config.py.orig	2017-07-23 07:12:16 UTC
+++ google_compute_engine/boto/boto_config.py
@@ -18,8 +18,8 @@
 If a project ID is not provided, this request the project ID from the
 metadata server and install the compute authentication plugin.
 
-Note the config starts with the content in /etc/boto.cfg.template,
-overrides settings, and then persists it into /etc/boto.cfg. This
+Note the config starts with the content in %%PREFIX%%/etc/boto.cfg.template,
+overrides settings, and then persists it into %%PREFIX%%/etc/boto.cfg. This
 is done so that the system boto.cfg can be removed prior to image
 packaging.
 """
@@ -34,8 +34,8 @@ from google_compute_engine import metada
 class BotoConfig(object):
   """Creates a boto config file for standalone GSUtil."""
 
-  boto_config = '/etc/boto.cfg'
-  boto_config_template = '/etc/boto.cfg.template'
+  boto_config = '%%PREFIX%%/etc/boto.cfg'
+  boto_config_template = '%%PREFIX%%/etc/boto.cfg.template'
   boto_config_script = os.path.abspath(__file__)
   boto_config_header = (
       'This file is automatically created at boot time by the %s script. Do '
