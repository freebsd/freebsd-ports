# See files/patch-certbot-compat-misc.py

--- tests/cli_test.py.orig	2023-03-07 21:17:25 UTC
+++ tests/cli_test.py
@@ -1,6 +1,7 @@
 """Tests for certbot._internal.cli."""
 import argparse
 import copy
+import sys
 from importlib import reload as reload_module
 import io
 import sys
@@ -60,9 +61,14 @@ class FlagDefaultTest(unittest.TestCase):
 
     def test_default_directories(self):
         if os.name != 'nt':
-            assert cli.flag_default('config_dir') == '/etc/letsencrypt'
-            assert cli.flag_default('work_dir') == '/var/lib/letsencrypt'
-            assert cli.flag_default('logs_dir') == '/var/log/letsencrypt'
+            if sys.platform.startswith('freebsd') or sys.platform.startswith('dragonfly'):
+                assert cli.flag_default('config_dir') == '/usr/local/etc/letsencrypt'
+                assert cli.flag_default('work_dir') == '/var/db/letsencrypt'
+                assert cli.flag_default('logs_dir') == '/var/log/letsencrypt'
+            else:
+                assert cli.flag_default('config_dir') == '/etc/letsencrypt'
+                assert cli.flag_default('work_dir') == '/var/lib/letsencrypt'
+                assert cli.flag_default('logs_dir') == '/var/log/letsencrypt'
         else:
             assert cli.flag_default('config_dir') == 'C:\\Certbot'
             assert cli.flag_default('work_dir') == 'C:\\Certbot\\lib'
