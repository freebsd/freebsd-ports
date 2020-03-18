# See files/patch-certbot-compat-misc.py

--- tests/cli_test.py.orig	2020-03-03 20:36:36 UTC
+++ tests/cli_test.py
@@ -1,6 +1,7 @@
 """Tests for certbot._internal.cli."""
 import argparse
 import copy
+import sys
 import tempfile
 import unittest
 
@@ -58,9 +59,14 @@ class FlagDefaultTest(unittest.TestCase):
 
     def test_default_directories(self):
         if os.name != 'nt':
-            self.assertEqual(cli.flag_default('config_dir'), '/etc/letsencrypt')
-            self.assertEqual(cli.flag_default('work_dir'), '/var/lib/letsencrypt')
-            self.assertEqual(cli.flag_default('logs_dir'), '/var/log/letsencrypt')
+            if sys.platform.startswith('freebsd') or sys.platform.startswith('dragonfly'):
+                self.assertEqual(cli.flag_default('config_dir'), '/usr/local/etc/letsencrypt')
+                self.assertEqual(cli.flag_default('work_dir'), '/var/db/letsencrypt')
+                self.assertEqual(cli.flag_default('logs_dir'), '/var/log/letsencrypt')
+            else:
+                self.assertEqual(cli.flag_default('config_dir'), '/etc/letsencrypt')
+                self.assertEqual(cli.flag_default('work_dir'), '/var/lib/letsencrypt')
+                self.assertEqual(cli.flag_default('logs_dir'), '/var/log/letsencrypt')
         else:
             self.assertEqual(cli.flag_default('config_dir'), 'C:\\Certbot')
             self.assertEqual(cli.flag_default('work_dir'), 'C:\\Certbot\\lib')
