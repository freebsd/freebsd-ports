This was part of a pull request that has been merged upstream. Most likely
this patch can be removed on the next release of python-fido2.

See https://github.com/Yubico/python-fido2/pull/64 and
https://github.com/Yubico/python-fido2/commit/19c86d5459931b8a76d1adc76420a8a1e0c0cf2e

--- test/_pyu2f/linux_test.py.orig	2019-09-13 11:17:23 UTC
+++ test/_pyu2f/linux_test.py
@@ -27,7 +27,11 @@ from fido2._pyu2f import linux
 try:
   from pyfakefs import fake_filesystem  # pylint: disable=g-import-not-at-top
 except ImportError:
-  from fakefs import fake_filesystem  # pylint: disable=g-import-not-at-top
+  try:
+    from fakefs import fake_filesystem  # pylint: disable=g-import-not-at-top
+  except ImportError:
+    if sys.platform.startswith('linux'):
+      raise
 
 if sys.version_info[:2] < (2, 7):
   import unittest2 as unittest  # pylint: disable=g-import-not-at-top
@@ -71,6 +75,8 @@ class FakeDeviceOsModule(object):
     return self.data_to_return
 
 
+@unittest.skipIf(not sys.platform.startswith('linux'),
+                 'Linux specific test case')
 class LinuxTest(unittest.TestCase):
   def setUp(self):
     self.fs = fake_filesystem.FakeFilesystem()
