--- src/mailman/core/initialize.py.orig	2017-11-18 01:23:39 UTC
+++ src/mailman/core/initialize.py
@@ -67,12 +67,12 @@ def search_for_configuration_file():
     config_path = os.path.join(os.getenv('HOME', '~'), '.mailman.cfg')
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
-    # /etc/mailman.cfg
-    config_path = '/etc/mailman.cfg'
+    # /usr/local/etc/mailman.cfg
+    config_path = '/usr/local/etc/mailman.cfg'
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
-    # /etc/mailman3/mailman.cfg
-    config_path = '/etc/mailman3/mailman.cfg'
+    # /usr/local/etc/mailman3/mailman.cfg
+    config_path = '/usr/local/etc/mailman3/mailman.cfg'
     if os.path.exists(config_path):
         return os.path.abspath(config_path)
     # $argv0/../../etc/mailman.cfg
