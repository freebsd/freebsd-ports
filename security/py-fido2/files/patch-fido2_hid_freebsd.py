See https://github.com/Yubico/python-fido2/commit/2a202d0e19fdb7be
--- fido2/hid/freebsd.py.orig	2022-05-27 09:25:33 UTC
+++ fido2/hid/freebsd.py
@@ -15,19 +15,39 @@
 # Modified work Copyright 2020 Yubico AB. All Rights Reserved.
 # This file, with modifications, is licensed under the above Apache License.
 
+# FreeBSD HID driver.
+#
+# There are two options to access UHID on FreeBSD:
+#
+# hidraw(4) - New method, not enabled by default
+#             on FreeBSD 13.x and earlier
+# uhid(4) - Classic method, default option on
+#           FreeBSD 13.x and earlier
+#
+# uhid is available since FreeBSD 13 and can be activated by adding
+# `hw.usb.usbhid.enable="1"` to `/boot/loader.conf`. The actual kernel
+# module is loaded with `kldload hidraw`.
 
-from __future__ import absolute_import
+from __future__ import annotations
 
 from ctypes.util import find_library
 import ctypes
+import fcntl
 import glob
 import re
+import struct
 import os
+from array import array
 
 from .base import HidDescriptor, parse_report_descriptor, FileCtapHidConnection
 
 import logging
+import sys
+from typing import Dict, Optional, Set, Union
 
+# Don't typecheck this file on Windows
+assert sys.platform != "win32"  # nosec
+
 logger = logging.getLogger(__name__)
 
 
@@ -39,9 +59,17 @@ sernum_re = re.compile('sernum="([^"]+)')
 
 libc = ctypes.CDLL(find_library("c"))
 
+# /usr/include/dev/usb/usb_ioctl.h
 USB_GET_REPORT_DESC = 0xC0205515
 
+# /usr/include/dev/hid/hidraw.h>
+HIDIOCGRAWINFO = 0x40085520
+HIDIOCGRDESC = 0x2000551F
+HIDIOCGRDESCSIZE = 0x4004551E
+HIDIOCGRAWNAME_128 = 0x40805521
+HIDIOCGRAWUNIQ_64 = 0x40405525
 
+
 class usb_gen_descriptor(ctypes.Structure):
     _fields_ = [
         (
@@ -62,8 +90,17 @@ class usb_gen_descriptor(ctypes.Structure):
     ]
 
 
+class HidrawCtapHidConnection(FileCtapHidConnection):
+    def write_packet(self, packet):
+        # Prepend the report ID
+        super(HidrawCtapHidConnection, self).write_packet(b"\0" + packet)
+
+
 def open_connection(descriptor):
-    return FileCtapHidConnection(descriptor)
+    if descriptor.path.find(devdir + "hidraw") == 0:
+        return HidrawCtapHidConnection(descriptor)
+    else:
+        return FileCtapHidConnection(descriptor)
 
 
 def _get_report_data(fd, report_type):
@@ -71,7 +108,7 @@ def _get_report_data(fd, report_type):
     desc = usb_gen_descriptor(
         ugd_data=ctypes.addressof(data),
         ugd_maxlen=ctypes.sizeof(data),
-        report_type=report_type,
+        ugd_report_type=report_type,
     )
     ret = libc.ioctl(fd, USB_GET_REPORT_DESC, ctypes.byref(desc))
     if ret != 0:
@@ -104,16 +141,16 @@ def _enumerate():
         if retval != 0:
             continue
 
-        dev = {}
+        dev: Dict[str, Optional[Union[str, int]]] = {}
         dev["name"] = uhid[len(devdir) :]
         dev["path"] = uhid
 
         value = ovalue.value[: olen.value].decode()
         m = vendor_re.search(value)
-        dev["vendor_id"] = m.group(1) if m else None
+        dev["vendor_id"] = int(m.group(1), 16) if m else None
 
         m = product_re.search(value)
-        dev["product_id"] = m.group(1) if m else None
+        dev["product_id"] = int(m.group(1), 16) if m else None
 
         m = sernum_re.search(value)
         dev["serial_number"] = m.group(1) if m else None
@@ -126,7 +163,49 @@ def _enumerate():
         yield dev
 
 
+def get_hidraw_descriptor(path):
+    with open(path, "rb") as f:
+        # Read VID, PID
+        buf = array("B", [0] * (4 + 2 + 2))
+        fcntl.ioctl(f, HIDIOCGRAWINFO, buf, True)
+        _, vid, pid = struct.unpack("<IHH", buf)
+
+        # FreeBSD's hidraw(4) does not return string length for
+        # HIDIOCGRAWNAME and HIDIOCGRAWUNIQ, see https://reviews.freebsd.org/D35233
+
+        # Read product
+        buf = array("B", [0] * 129)
+        fcntl.ioctl(f, HIDIOCGRAWNAME_128, buf, True)
+        length = buf.index(0) + 1  # emulate ioctl return value
+        name = bytearray(buf[: (length - 1)]).decode("utf-8") if length > 1 else None
+
+        # Read unique ID
+        try:
+            buf = array("B", [0] * 65)
+            fcntl.ioctl(f, HIDIOCGRAWUNIQ_64, buf, True)
+            length = buf.index(0) + 1  # emulate ioctl return value
+            serial = (
+                bytearray(buf[: (length - 1)]).decode("utf-8") if length > 1 else None
+            )
+        except OSError:
+            serial = None
+
+        # Read report descriptor
+        buf = array("B", [0] * 4)
+        fcntl.ioctl(f, HIDIOCGRDESCSIZE, buf, True)
+        size = struct.unpack("<I", buf)[0]
+        buf += array("B", [0] * size)
+        fcntl.ioctl(f, HIDIOCGRDESC, buf, True)
+
+    data = bytearray(buf[4:])
+    max_in_size, max_out_size = parse_report_descriptor(data)
+    return HidDescriptor(path, vid, pid, max_in_size, max_out_size, name, serial)
+
+
 def get_descriptor(path):
+    if path.find(devdir + "hidraw") == 0:
+        return get_hidraw_descriptor(path)
+
     for dev in _enumerate():
         if dev["path"] == path:
             vid = dev["vendor_id"]
@@ -137,21 +216,50 @@ def get_descriptor(path):
     raise ValueError("Device not found")
 
 
+# Cache for continuously failing devices
+_failed_cache: Set[str] = set()
+
+
 def list_descriptors():
+    stale = set(_failed_cache)
     descriptors = []
-    for dev in _enumerate():
+    for hidraw in glob.glob(devdir + "hidraw?*"):
+        stale.discard(hidraw)
         try:
-            name = dev["product_desc"] or None
-            serial = (dev["serial_number"] if "serial_number" in dev else None) or None
-            descriptors.append(
-                _read_descriptor(
-                    dev["vendor_id"], dev["product_id"], name, serial, dev["path"],
-                )
-            )
-            logger.debug("Found CTAP device: %s", dev["path"])
+            descriptors.append(get_descriptor(hidraw))
         except ValueError:
             pass  # Not a CTAP device, ignore
-        except Exception as e:
-            logger.debug("Failed opening HID device", exc_info=e)
+        except Exception:
+            if hidraw not in _failed_cache:
+                logger.debug("Failed opening device %s", hidraw, exc_info=True)
+                _failed_cache.add(hidraw)
+
+    if not descriptors:
+        for dev in _enumerate():
+            path = dev["path"]
+            stale.discard(path)
+            try:
+                name = dev["product_desc"] or None
+                serial = (
+                    dev["serial_number"] if "serial_number" in dev else None
+                ) or None
+                descriptors.append(
+                    _read_descriptor(
+                        dev["vendor_id"],
+                        dev["product_id"],
+                        name,
+                        serial,
+                        path,
+                    )
+                )
+            except ValueError:
+                pass  # Not a CTAP device, ignore
+            except Exception:
+                if path not in _failed_cache:
+                    logger.debug("Failed opening HID device %s", path, exc_info=True)
+                    _failed_cache.add(path)
+
+    # Remove entries from the cache that were not seen
+    _failed_cache.difference_update(stale)
 
     return descriptors
