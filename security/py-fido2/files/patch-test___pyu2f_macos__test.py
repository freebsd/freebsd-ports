This was part of a pull request that has been merged upstream. Most likely
this patch can be removed on the next release of python-fido2.

See https://github.com/Yubico/python-fido2/pull/64 and
https://github.com/Yubico/python-fido2/commit/19c86d5459931b8a76d1adc76420a8a1e0c0cf2e

--- test/_pyu2f/macos_test.py.orig	2018-07-04 13:27:36 UTC
+++ test/_pyu2f/macos_test.py
@@ -44,6 +44,8 @@ def init_mock_get_int_property(mock_get_int_property):
   mock_get_int_property.return_value = 64
 
 
+@unittest.skipIf(not sys.platform.startswith('darwin'),
+                 'MacOS specific test case')
 class MacOsTest(unittest.TestCase):
 
   @classmethod
