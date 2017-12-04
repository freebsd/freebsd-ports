--- device/hid/hid_device_info_freebsd.cc.orig	2017-12-03 15:37:32.159794000 -0800
+++ device/hid/hid_device_info_freebsd.cc	2017-12-03 15:37:32.162092000 -0800
@@ -0,0 +1,30 @@
+// Copyright 2015 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "hid_device_info_freebsd.h"
+
+namespace device {
+
+HidDeviceInfoFreeBSD::HidDeviceInfoFreeBSD(
+    const HidDeviceId& device_id,
+    const std::string& device_node,
+    uint16_t vendor_id,
+    uint16_t product_id,
+    const std::string& product_name,
+    const std::string& serial_number,
+    HidBusType bus_type,
+    const std::vector<uint8_t> report_descriptor)
+    : HidDeviceInfo(device_id,
+                    vendor_id,
+                    product_id,
+                    product_name,
+                    serial_number,
+                    bus_type,
+                    report_descriptor),
+      device_node_(device_node) {}
+
+HidDeviceInfoFreeBSD::~HidDeviceInfoFreeBSD() {
+}
+
+}  // namespace device
