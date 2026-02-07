--- cloudinit/settings.py.orig	2025-08-12 19:00:58 UTC
+++ cloudinit/settings.py
@@ -12,11 +12,11 @@ CFG_ENV_NAME = "CLOUD_CFG"
 CFG_ENV_NAME = "CLOUD_CFG"
 
 # This is expected to be a yaml formatted file
-CLOUD_CONFIG = "/etc/cloud/cloud.cfg"
+CLOUD_CONFIG = "%%PREFIX%%/etc/cloud/cloud.cfg"
 
-CLEAN_RUNPARTS_DIR = "/etc/cloud/clean.d"
+CLEAN_RUNPARTS_DIR = "%%PREFIX%%/etc/cloud/clean.d"
 
-DEFAULT_RUN_DIR = "/run/cloud-init"
+DEFAULT_RUN_DIR = "/var/run/cloud-init"
 
 # What u get if no config is provided
 CFG_BUILTIN = {
@@ -60,8 +60,8 @@ CFG_BUILTIN = {
     "system_info": {
         "paths": {
             "cloud_dir": "/var/lib/cloud",
-            "docs_dir": "/usr/share/doc/cloud-init/",
-            "templates_dir": "/etc/cloud/templates/",
+            "docs_dir": "%%PREFIX%%/share/doc/cloud-init/",
+            "templates_dir": "%%PREFIX%%/etc/cloud/templates/",
         },
         "distro": "ubuntu",
         "network": {"renderers": None},
