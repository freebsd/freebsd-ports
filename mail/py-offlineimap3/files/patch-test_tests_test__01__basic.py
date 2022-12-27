--- test/tests/test_01_basic.py.orig	2022-03-04 03:43:46 UTC
+++ test/tests/test_01_basic.py
@@ -17,6 +17,8 @@ import unittest
 import logging
 from test.OLItest import OLITestLib
 
+import pytest
+
 # Things need to be setup first, usually setup.py initializes everything.
 # but if e.g. called from command line, we take care of default values here:
 if not OLITestLib.cred_file:
@@ -47,6 +49,7 @@ class TestBasicFunctions(unittest.TestCase):
     def tearDown(self):
         OLITestLib.delete_remote_testfolders()
 
+    @pytest.mark.skip(reason="skpping test needs remote auth")
     def test_01_olistartup(self):
         """Tests if OLI can be invoked without exceptions
 
@@ -60,6 +63,7 @@ class TestBasicFunctions(unittest.TestCase):
                             "mails, but sync led to {0} folders and {1} mails"
                         .format(boxes, mails))
 
+    @pytest.mark.skip(reason="skpping test needs remote auth")
     def test_02_createdir(self):
         """Create local 'OLItest 1', sync"""
         OLITestLib.delete_maildir('')  # Delete all local maildir folders
@@ -71,6 +75,7 @@ class TestBasicFunctions(unittest.TestCase):
                             "mails, but sync led to {0} folders and {1} mails"
                         .format(boxes, mails))
 
+    @pytest.mark.skip(reason="skpping test needs remote auth")
     def test_03_createdir_quote(self):
         """Create local 'OLItest "1"' maildir, sync
 
@@ -87,6 +92,7 @@ class TestBasicFunctions(unittest.TestCase):
                             "mails, but sync led to {0} folders and {1} mails"
                         .format(boxes, mails))
 
+    @pytest.mark.skip(reason="skpping test needs remote auth")
     def test_04_nametransmismatch(self):
         """Create mismatching remote and local nametrans rules
 
@@ -108,6 +114,7 @@ class TestBasicFunctions(unittest.TestCase):
         # Write out default config file again
         OLITestLib.write_config_file()
 
+    @pytest.mark.skip(reason="skpping test needs remote auth")
     def test_05_createmail(self):
         """Create mail in OLItest 1, sync, wipe folder sync
 
@@ -133,6 +140,7 @@ class TestBasicFunctions(unittest.TestCase):
                              "assigned the IMAP's UID number, but {0} messages had no valid ID "
                          .format(len([None for x in uids if x is None])))
 
+    @pytest.mark.skip(reason="skpping test needs remote auth")
     def test_06_createfolders(self):
         """Test if createfolders works as expected
 
