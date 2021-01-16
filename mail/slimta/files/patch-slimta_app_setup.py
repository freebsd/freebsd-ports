--- slimta/app/setup.py.orig	2021-01-11 18:41:23 UTC
+++ slimta/app/setup.py
@@ -55,7 +55,7 @@ def _try_config_copy(etc_dir, conf_file, force):
 
 def _setup_configs(args):
     etc_dir = args.etc_dir
-    default_etc_dir = '/etc/slimta'
+    default_etc_dir = '%%PREFIX%%/etc/slimta'
     if os.getuid() != 0:
         default_etc_dir = '~/.slimta/'
     if etc_dir is None:
