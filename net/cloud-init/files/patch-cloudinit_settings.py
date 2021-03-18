--- cloudinit/settings.py.orig	2021-03-17 15:43:42 UTC
+++ cloudinit/settings.py
@@ -12,7 +12,7 @@
 CFG_ENV_NAME = "CLOUD_CFG"
 
 # This is expected to be a yaml formatted file
-CLOUD_CONFIG = '/etc/cloud/cloud.cfg'
+CLOUD_CONFIG = '%%PREFIX%%/etc/cloud/cloud.cfg'
 
 RUN_CLOUD_CONFIG = '/run/cloud-init/cloud.cfg'
 
@@ -50,7 +50,7 @@ CFG_BUILTIN = {
     'system_info': {
         'paths': {
             'cloud_dir': '/var/lib/cloud',
-            'templates_dir': '/etc/cloud/templates/',
+            'templates_dir': '%%PREFIX%%/etc/cloud/templates/',
         },
         'distro': 'ubuntu',
         'network': {'renderers': None},
