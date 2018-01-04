--- device/hid/hid_device_info_freebsd.h.orig	2017-12-03 15:37:32.162846000 -0800
+++ device/hid/hid_device_info_freebsd.h	2017-12-03 15:37:32.165247000 -0800
@@ -0,0 +1,35 @@
+// Copyright 2015 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_DEVICE_INFO_LINUX_H_
+#define DEVICE_HID_HID_DEVICE_INFO_LINUX_H_
+
+#include <stdint.h>
+
+#include "device/hid/hid_device_info.h"
+
+namespace device {
+
+class HidDeviceInfoFreeBSD : public HidDeviceInfo {
+ public:
+  HidDeviceInfoFreeBSD(const HidDeviceId& device_id,
+                     const std::string& device_node,
+                     uint16_t vendor_id,
+                     uint16_t product_id,
+                     const std::string& product_name,
+                     const std::string& serial_number,
+                     HidBusType bus_type,
+                     const std::vector<uint8_t> report_descriptor);
+
+  const std::string& device_node() const { return device_node_; }
+
+ private:
+  ~HidDeviceInfoFreeBSD() override;
+
+  std::string device_node_;
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_DEVICE_INFO_LINUX_H_
