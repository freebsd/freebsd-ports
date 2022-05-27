See https://github.com/Yubico/yubikey-manager/commit/ecd7897b3f02054
--- ykman/hid/freebsd.py.orig	2022-05-27 13:02:44 UTC
+++ ykman/hid/freebsd.py
@@ -0,0 +1,297 @@
+# Original work Copyright 2016 Google Inc. All Rights Reserved.
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
+#
+# Modified work Copyright 2022 Michael Gmelin. All Rights Reserved.
+# This file, with modifications, is licensed under the above Apache License.
+#
+# Modified work Copyright 2022 Yubico AB. All Rights Reserved.
+# This file, with modifications, is licensed under the above Apache License.
+
+# FreeBSD HID driver.
+#
+# There are two options to access UHID on FreeBSD:
+#
+# hidraw(4) - New method, not enabled by default
+#             on FreeBSD 13.x and earlier
+# uhid(4) - Classic method, default option on
+#           FreeBSD 13.x and earlier
+#
+# To avoid attaching the Yubikey as a keyboard, do:
+#
+#     usbconfig ugenX.Y add_quirk UQ_KBD_IGNORE
+#     usbconfig ugenX.Y reset
+#
+# The list of available devices is shown using `usbconfig list`
+# You can make these changes permanent by altering loader.conf.
+#
+# Starting from FreeBSD 13 hidraw(4) can be enabled using:
+#
+#     sysrc kld_list+="hidraw hkbd"
+#     cat >>/boot/loader.conf<<EOF
+#     hw.usb.usbhid.enable="1"
+#     hw.usb.quirk.0="0x1050 0x0010 0 0xffff UQ_KBD_IGNORE"  # YKS_OTP
+#     hw.usb.quirk.1="0x1050 0x0110 0 0xffff UQ_KBD_IGNORE"  # NEO_OTP
+#     hw.usb.quirk.2="0x1050 0x0111 0 0xffff UQ_KBD_IGNORE"  # NEO_OTP_CCID
+#     hw.usb.quirk.3="0x1050 0x0114 0 0xffff UQ_KBD_IGNORE"  # NEO_OTP_FIDO
+#     hw.usb.quirk.4="0x1050 0x0116 0 0xffff UQ_KBD_IGNORE"  # NEO_OTP_FIDO_CCID
+#     hw.usb.quirk.5="0x1050 0x0401 0 0xffff UQ_KBD_IGNORE"  # YK4_OTP
+#     hw.usb.quirk.6="0x1050 0x0403 0 0xffff UQ_KBD_IGNORE"  # YK4_OTP_FIDO
+#     hw.usb.quirk.7="0x1050 0x0405 0 0xffff UQ_KBD_IGNORE"  # YK4_OTP_CCID
+#     hw.usb.quirk.8="0x1050 0x0407 0 0xffff UQ_KBD_IGNORE"  # YK4_OTP_FIDO_CCID
+#     hw.usb.quirk.9="0x1050 0x0410 0 0xffff UQ_KBD_IGNORE"  # YKP_OTP_FIDO
+#     EOF
+#     reboot
+#
+from yubikit.core.otp import OtpConnection
+from .base import OtpYubiKeyDevice, YUBICO_VID, USAGE_OTP
+
+from ctypes.util import find_library
+import ctypes
+
+import glob
+import fcntl
+import os
+import re
+import struct
+import logging
+
+logger = logging.getLogger(__name__)
+
+devdir = "/dev/"
+
+# /usr/include/dev/ususb_ioctl.h
+USB_GET_REPORT = 0xC0205517
+USB_SET_REPORT = 0x80205518
+USB_GET_REPORT_DESC = 0xC0205515
+
+# /usr/include/dev/hid/hidraw.h>
+HIDIOCGRAWINFO = 0x40085520
+HIDIOCGRDESC = 0x2000551F
+HIDIOCGRDESCSIZE = 0x4004551E
+HIDIOCGFEATURE_9 = 0xC0095524
+HIDIOCSFEATURE_9 = 0x80095523
+
+
+class HidrawConnection(OtpConnection):
+    """
+    hidraw(4) is FreeBSD's modern raw access driver, based on usbhid(4).
+    It is available since FreeBSD 13 and can be activated by adding
+    `hw.usb.usbhid.enable="1"` to `/boot/loader.conf`. The actual kernel
+    module is loaded with `kldload hidraw`.
+    """
+
+    def __init__(self, path):
+        self.fd = os.open(path, os.O_RDWR)
+
+    def close(self):
+        os.close(self.fd)
+
+    def receive(self):
+        buf = bytearray(1 + 8)
+        fcntl.ioctl(self.fd, HIDIOCGFEATURE_9, buf, True)
+        return buf[1:]
+
+    def send(self, data):
+        buf = bytes([0]) + data
+        fcntl.ioctl(self.fd, HIDIOCSFEATURE_9, buf)
+
+    @staticmethod
+    def get_info(dev):
+        buf = bytearray(4 + 2 + 2)
+        fcntl.ioctl(dev, HIDIOCGRAWINFO, buf, True)
+        return struct.unpack("<IHH", buf)
+
+    @staticmethod
+    def get_descriptor(dev):
+        buf = bytearray(4)
+        fcntl.ioctl(dev, HIDIOCGRDESCSIZE, buf, True)
+        size = struct.unpack("<I", buf)[0]
+        buf += bytearray(size)
+        fcntl.ioctl(dev, HIDIOCGRDESC, buf, True)
+        return buf[4:]
+
+    @staticmethod
+    def get_usage(dev):
+        buf = HidrawConnection.get_descriptor(dev)
+        usage, usage_page = (None, None)
+        while buf:
+            head, buf = buf[0], buf[1:]
+            typ, size = 0xFC & head, 0x03 & head
+            value, buf = buf[:size], buf[size:]
+            if typ == 4:  # Usage page
+                usage_page = struct.unpack("<I", value.ljust(4, b"\0"))[0]
+                if usage is not None:
+                    return usage_page, usage
+            elif typ == 8:  # Usage
+                usage = struct.unpack("<I", value.ljust(4, b"\0"))[0]
+                if usage_page is not None:
+                    return usage_page, usage
+
+    @staticmethod
+    def list_devices():
+        devices = []
+        for hidraw in glob.glob(devdir + "hidraw?*"):
+            try:
+                with open(hidraw, "rb") as f:
+                    bustype, vid, pid = HidrawConnection.get_info(f)
+                    if vid == YUBICO_VID and HidrawConnection.get_usage(f) == USAGE_OTP:
+                        devices.append(OtpYubiKeyDevice(hidraw, pid, HidrawConnection))
+            except Exception as e:
+                logger.debug("Failed opening HID device", exc_info=e)
+                continue
+        return devices
+
+
+# For UhidConnection
+libc = ctypes.CDLL(find_library("c"))
+
+
+class usb_gen_descriptor(ctypes.Structure):
+    _fields_ = [
+        (
+            "ugd_data",
+            ctypes.c_void_p,
+        ),
+        ("ugd_lang_id", ctypes.c_uint16),
+        ("ugd_maxlen", ctypes.c_uint16),
+        ("ugd_actlen", ctypes.c_uint16),
+        ("ugd_offset", ctypes.c_uint16),
+        ("ugd_config_index", ctypes.c_uint8),
+        ("ugd_string_index", ctypes.c_uint8),
+        ("ugd_iface_index", ctypes.c_uint8),
+        ("ugd_altif_index", ctypes.c_uint8),
+        ("ugd_endpt_index", ctypes.c_uint8),
+        ("ugd_report_type", ctypes.c_uint8),
+        ("reserved", ctypes.c_uint8 * 8),
+    ]
+
+
+class UhidConnection(OtpConnection):
+    """
+    uhid(4) is FreeBSD's classic USB hid access driver and enabled
+    by default in FreeBSD 13.x and earlier.
+    """
+
+    def __init__(self, path):
+        self.fd = os.open(path, os.O_RDWR)
+
+    def close(self):
+        os.close(self.fd)
+
+    def receive(self):
+        buf = ctypes.create_string_buffer(9)
+        desc = usb_gen_descriptor(
+            ugd_data=ctypes.addressof(buf),
+            ugd_maxlen=ctypes.sizeof(buf),
+            ugd_report_type=3,
+        )
+        ret = libc.ioctl(self.fd, USB_GET_REPORT, ctypes.pointer(desc))
+        if ret != 0:
+            raise ValueError("ioctl failed: " + str(ret))
+        return buf[:-1]
+
+    def send(self, data):
+        buf = ctypes.create_string_buffer(8)
+        for i in range(0, len(data)):
+            buf[i] = data[i]
+
+        desc = usb_gen_descriptor(
+            ugd_data=ctypes.addressof(buf),
+            ugd_maxlen=len(buf),
+            ugd_report_type=0x3,
+        )
+        ret = libc.ioctl(self.fd, USB_SET_REPORT, ctypes.pointer(desc))
+        if ret != 0:
+            raise ValueError("ioctl failed: " + str(ret))
+
+    @staticmethod
+    def get_usage(dev):
+        c_data = ctypes.create_string_buffer(4096)
+        desc = usb_gen_descriptor(
+            ugd_data=ctypes.addressof(c_data),
+            ugd_maxlen=ctypes.sizeof(c_data),
+            ugd_report_type=3,
+        )
+        ret = libc.ioctl(dev, USB_GET_REPORT_DESC, ctypes.pointer(desc))
+        if ret != 0:
+            raise ValueError("ioctl failed")
+
+        REPORT_DESCRIPTOR_KEY_MASK = 0xFC
+        SIZE_MASK = ~REPORT_DESCRIPTOR_KEY_MASK
+        USAGE_PAGE = 0x04
+        USAGE = 0x08
+
+        data = c_data.raw
+        usage, usage_page = (None, None)
+        while data and not (usage and usage_page):
+            head, data = struct.unpack_from(">B", data)[0], data[1:]
+            key, size = REPORT_DESCRIPTOR_KEY_MASK & head, SIZE_MASK & head
+            value = struct.unpack_from("<I", data[:size].ljust(4, b"\0"))[0]
+            data = data[size:]
+            if key == USAGE_PAGE and not usage_page:
+                usage_page = value
+            elif key == USAGE and not usage:
+                usage = value
+
+        return (usage_page, usage)
+
+    @staticmethod
+    def get_info(index):
+        vendor_re = re.compile("vendor=(0x[0-9a-fA-F]+)")
+        product_re = re.compile("product=(0x[0-9a-fA-F]+)")
+        sernum_re = re.compile('sernum="([^"]+)')
+
+        pnpinfo = ("dev.uhid." + index + ".%pnpinfo").encode()
+
+        ovalue = ctypes.create_string_buffer(1024)
+        olen = ctypes.c_size_t(ctypes.sizeof(ovalue))
+        key = ctypes.c_char_p(pnpinfo)
+        retval = libc.sysctlbyname(key, ovalue, ctypes.byref(olen), None, None)
+        if retval != 0:
+            raise IOError("sysctlbyname failed")
+
+        value = ovalue.value[: olen.value].decode()
+        m = vendor_re.search(value)
+        vid = int(m.group(1), 16) if m else None
+        m = product_re.search(value)
+        pid = int(m.group(1), 16) if m else None
+        m = sernum_re.search(value)
+        serial = m.group(1) if m else None
+        return (vid, pid, serial)
+
+    @staticmethod
+    def list_devices():
+        devices = []
+        for uhid in glob.glob(devdir + "uhid?*"):
+            index = uhid[len(devdir) + len("uhid") :]
+            if not index.isdigit():
+                continue
+
+            try:
+                (vid, pid, serial) = UhidConnection.get_info(index)
+                if vid == YUBICO_VID:
+                    with open(uhid, "rb") as f:
+                        if UhidConnection.get_usage(f.fileno()) == USAGE_OTP:
+                            devices.append(OtpYubiKeyDevice(uhid, pid, UhidConnection))
+            except Exception as e:
+                logger.debug("Failed opening HID device", exc_info=e)
+                continue
+        return devices
+
+
+def list_devices():
+    devices = HidrawConnection.list_devices()
+    if not devices:
+        devices = UhidConnection.list_devices()
+    return devices
