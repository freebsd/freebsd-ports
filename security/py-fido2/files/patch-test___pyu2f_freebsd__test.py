This was part of a pull request that has been merged upstream. Most likely
this patch can be removed on the next release of python-fido2.

See https://github.com/Yubico/python-fido2/pull/64 and
https://github.com/Yubico/python-fido2/commit/19c86d5459931b8a76d1adc76420a8a1e0c0cf2e

--- test/_pyu2f/freebsd_test.py.orig	2019-09-13 11:01:05 UTC
+++ test/_pyu2f/freebsd_test.py
@@ -0,0 +1,122 @@
+# Copyright 2016 Google Inc. All Rights Reserved.
+#
+# Licensed under the Apache License, Version 2.0 (the "License");
+# you may not use this file except in compliance with the License.
+# You may obtain a copy of the License at
+#
+#    http://www.apache.org/licenses/LICENSE-2.0
+#
+# Unless required by applicable law or agreed to in writing, software
+# distributed under the License is distributed on an "AS IS" BASIS,
+# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+# See the License for the specific language governing permissions and
+# limitations under the License.
+
+"""Tests for _pyu2f.hid.freebsd."""
+
+import base64
+import os
+import sys
+
+import six
+from six.moves import builtins
+from mock import patch
+
+if sys.platform.startswith('freebsd'):
+    from fido2._pyu2f import freebsd
+
+if sys.version_info[:2] < (2, 7):
+    import unittest2 as unittest  # pylint: disable=g-import-not-at-top
+else:
+    import unittest  # pylint: disable=g-import-not-at-top
+
+
+# These are base64 encoded report descriptors of a Yubico token
+# and a Logitech keyboard.
+YUBICO_RD = 'BtDxCQGhAQkgFQAm/wB1CJVAgQIJIRUAJv8AdQiVQJECwA=='
+KEYBOARD_RD = (
+    'BQEJAqEBCQGhAAUJGQEpBRUAJQGVBXUBgQKVAXUDgQEFAQkwCTEJOBWBJX91CJUDgQbAwA==')
+
+
+class FakeUhidFreeBSDModule():
+    def enumerate(self):
+        return [{'device': 'uhid0',
+                 'path': '/dev/uhid0',
+                 'vendor_id': 0x046d,
+                 'product_id': 0xc31c,
+                 'product_desc': 'Logitech Keyboard'},
+                {'device': 'uhid1',
+                 'path': '/dev/uhid1',
+                 'vendor_id': 0x1050,
+                 'product_id': 0x0407,
+                 'product_desc': 'Yubico U2F'}]
+
+    def get_report_data(self, fd, unused_report_id):
+        if fd:
+            return base64.b64decode(YUBICO_RD)
+        else:
+            return base64.b64decode(KEYBOARD_RD)
+
+
+class FakeOsModule():
+    O_RDONLY = os.O_RDONLY
+    O_RDWR = os.O_RDWR
+    path = os.path
+
+    data_written = None
+    data_to_return = None
+
+    def open(self, path, unused_opts):  # pylint: disable=invalid-name
+        if path.find('uhid1') >= 0:
+            return 1  # fd == 1 => magic number to return Yubikey RD below
+        else:
+            return 0
+
+    def write(self, unused_dev, data):  # pylint: disable=invalid-name
+        self.data_written = data
+
+    def read(self, unused_dev, unused_length):  # pylint: disable=invalid-name
+        return self.data_to_return
+
+    def close(self, unused_dev):  # pylint: disable=invalid-name
+        pass
+
+
+@unittest.skipIf(not sys.platform.startswith('freebsd'),
+                 'FreeBSD specific test case')
+class FreeBSDTest(unittest.TestCase):
+    @patch('fido2._pyu2f.freebsd.os', FakeOsModule())
+    @patch('fido2._pyu2f.freebsd.uhid_freebsd', FakeUhidFreeBSDModule())
+    def testCallEnumerate(self):
+        devs = list(freebsd.FreeBSDHidDevice.Enumerate())
+        devs = sorted(devs, key=lambda k: k['vendor_id'])
+
+        self.assertEqual(len(devs), 2)
+        self.assertEqual(devs[0]['vendor_id'], 0x046d)
+        self.assertEqual(devs[0]['product_id'], 0xc31c)
+        self.assertEqual(devs[1]['vendor_id'], 0x1050)
+        self.assertEqual(devs[1]['product_id'], 0x0407)
+        self.assertEqual(devs[1]['usage_page'], 0xf1d0)
+        self.assertEqual(devs[1]['usage'], 1)
+
+    @patch('fido2._pyu2f.freebsd.uhid_freebsd', FakeUhidFreeBSDModule())
+    def testCallOpen(self):
+        fake_os = FakeOsModule()
+        with patch('fido2._pyu2f.linux.os', fake_os):
+            with patch('fido2._pyu2f.freebsd.os', fake_os):
+                dev = freebsd.FreeBSDHidDevice('/dev/uhid1')
+                self.assertEqual(dev.GetInReportDataLength(), 64)
+                self.assertEqual(dev.GetOutReportDataLength(), 64)
+
+                dev.Write(list(range(0, 64)))
+                # The HidDevice implementation prepends one zero-byte-packet
+                # (64 bytes) representing the report ID + padding
+                self.assertEqual(list(six.iterbytes(fake_os.data_written)),
+                                 [0]*64 + list(range(0, 64)))
+
+                fake_os.data_to_return = b'x' * 64
+                self.assertEqual(dev.Read(), [120] * 64)  # chr(120) = 'x'
+
+
+if __name__ == '__main__':
+    unittest.main()
