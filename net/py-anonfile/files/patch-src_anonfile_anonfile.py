--- src/anonfile/anonfile.py.orig	2023-06-16 05:34:29 UTC
+++ src/anonfile/anonfile.py
@@ -65,7 +65,8 @@ def get_config_dir() -> Path:
     return {
         'Windows': Path(os.path.expandvars('%LOCALAPPDATA%')),
         'Darwin': Path.home().joinpath('Library').joinpath('Application Support'),
-        'Linux': Path.home().joinpath('.config')
+        'Linux': Path.home().joinpath('.config'),
+        'FreeBSD': Path.home().joinpath('.config')
     }[platform.system()].joinpath(package_name)
 
 def get_logfile_path() -> Path:
