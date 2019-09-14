This was part of a pull request that has been merged upstream. Most likely
this patch can be removed on the next release of python-fido2.

See https://github.com/Yubico/python-fido2/pull/64 and
https://github.com/Yubico/python-fido2/commit/19c86d5459931b8a76d1adc76420a8a1e0c0cf2e

--- fido2/_pyu2f/freebsd.py.orig	2019-09-12 11:35:02 UTC
+++ fido2/_pyu2f/freebsd.py
@@ -0,0 +1,54 @@
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
+"""Implements raw HID interface on FreeBSD using sysctl and device files."""
+
+from __future__ import absolute_import
+
+import os
+import uhid_freebsd
+
+from . import linux
+
+
+class FreeBSDHidDevice(linux.LinuxHidDevice):
+    """Implementation of HID device for FreeBSD.
+    """
+
+    @staticmethod
+    def Enumerate():
+        for dev in uhid_freebsd.enumerate():
+            desc = linux.base.DeviceDescriptor()
+            desc.path = dev["path"]
+            desc.vendor_id = dev["vendor_id"]
+            desc.product_id = dev["product_id"]
+            desc.product_string = dev["product_desc"]
+            fd = os.open(desc.path, os.O_RDONLY)
+            linux.ParseReportDescriptor(
+                uhid_freebsd.get_report_data(fd, 3), desc)
+            os.close(fd)
+            yield desc.ToPublicDict()
+
+    def __init__(self, path):
+        linux.base.HidDevice.__init__(self, path)
+        self.dev = os.open(path, os.O_RDWR)
+        self.desc = linux.base.DeviceDescriptor()
+        self.desc.path = path
+        linux.ParseReportDescriptor(
+            uhid_freebsd.get_report_data(self.dev, 3), self.desc)
+
+    def Write(self, packet):
+        """See base class."""
+        out = bytes(bytearray([0]*64 + packet))  # 64 zero bytes (report ID)
+        os.write(self.dev, out)
