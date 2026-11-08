--- tests/CLIConfigTest.py.orig	2026-08-07 01:15:15 UTC
+++ tests/CLIConfigTest.py
@@ -9,6 +9,7 @@ import unittest
 import tempfile
 from textwrap import dedent
 import unittest
+from unittest.mock import patch 
 
 from .TLib import *
 
@@ -239,7 +240,6 @@ class CLIClushConfigTest(unittest.TestCase):
 
     def testClushConfigSetRlimitValueError(self):
         """test CLI.Config.ClushConfig (setrlimit ValueError)"""
-        soft, hard = resource.getrlimit(resource.RLIMIT_NOFILE)
         f = tempfile.NamedTemporaryFile(prefix='testclushconfig')
         f.write(dedent("""
             [Main]
@@ -248,8 +248,7 @@ class CLIClushConfigTest(unittest.TestCase):
             command_timeout: 0
             history_size: 100
             color: auto
-            # Use wrong fd_max value to generate ValueError
-            fd_max: -1
+            fd_max: 200
             verbosity: 1""").encode())
         f.flush()
         parser = OptionParser("dummy")
@@ -261,17 +260,21 @@ class CLIClushConfigTest(unittest.TestCase):
         f.close()
         display = Display(options, config)
 
-        class TestException(Exception): pass
+        class TestException(Exception):
+            pass
 
         def mock_vprint_err(level, message):
             if message.startswith('Warning: Failed to set max open files'):
                 raise TestException()
 
         display.vprint_err = mock_vprint_err
-        self.assertRaises(TestException, set_fdlimit, config.fd_max, display)
 
-        soft2, _ = resource.getrlimit(resource.RLIMIT_NOFILE)
-        self.assertEqual(soft, soft2)
+        with patch('ClusterShell.CLI.Clush.resource.getrlimit',
+                   return_value=(100, 1000)), \
+             patch('ClusterShell.CLI.Clush.resource.setrlimit',
+                   side_effect=ValueError):
+            self.assertRaises(TestException,
+                              set_fdlimit, config.fd_max, display)
 
     def testClushConfigDefaultWithOptions(self):
         """test CLI.Config.ClushConfig (default with options)"""
