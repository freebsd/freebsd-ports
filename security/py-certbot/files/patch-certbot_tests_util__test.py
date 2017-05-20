From 42d07d756df0cf96c9d20b44e772858391d48384 Mon Sep 17 00:00:00 2001
From: Ryan Pineo <ry@tsl.io>
Date: Fri, 12 May 2017 15:45:54 -0400
Subject: [PATCH] support version 0.12.0 of configargparse

fixes #4648

--- certbot/tests/util_test.py.orig	2017-05-16 07:27:15 UTC
+++ certbot/tests/util_test.py
@@ -5,6 +5,7 @@ import os
 import stat
 import unittest
 
+import configargparse
 import mock
 import six
 
@@ -333,6 +334,22 @@ class AddDeprecatedArgumentTest(unittest
                 pass
         self.assertTrue("--old-option" not in stdout.getvalue())
 
+    def test_when_configargparse(self):
+        '''In configargparse version < 0.12.0 ACTION_TYPES_THAT_DONT_NEED_A_VALUE is a set.'''
+        orig = configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE
+        configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE = set()
+        self._call("--old-option", 1)
+        self.assertEqual(len(configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE), 1)
+        configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE = orig
+
+    def test_when_configargparse_tuple(self):
+        '''In configargparse version >= 0.12.0 ACTION_TYPES_THAT_DONT_NEED_A_VALUE is a tuple.'''
+        orig = configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE
+        configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE = tuple()
+        self._call("--old-option", 1)
+        self.assertEqual(len(configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE), 1)
+        configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE = orig
+
 
 class EnforceLeValidity(unittest.TestCase):
     """Test enforce_le_validity."""
