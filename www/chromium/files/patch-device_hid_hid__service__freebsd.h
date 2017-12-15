--- device/hid/hid_service_freebsd.h.orig	2017-12-03 15:37:32.180261000 -0800
+++ device/hid/hid_service_freebsd.h	2017-12-03 15:37:32.183647000 -0800
@@ -0,0 +1,47 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_SERVICE_FREEBSD_H_
+#define DEVICE_HID_HID_SERVICE_FREEBSD_H_
+
+#include <string>
+
+#include "base/macros.h"
+#include "base/memory/ref_counted.h"
+#include "base/memory/weak_ptr.h"
+#include "base/timer/timer.h"
+#include "device/hid/hid_service.h"
+#include "net/base/io_buffer.h"
+
+namespace device {
+
+class HidServiceFreeBSD : public HidService {
+ public:
+  HidServiceFreeBSD();
+  ~HidServiceFreeBSD() override;
+
+  void Connect(const HidDeviceId& device_id,
+               const ConnectCallback& connect) override;
+
+ private:
+  struct ConnectParams;
+  class BlockingTaskHelper;
+
+  static void OpenOnBlockingThread(std::unique_ptr<ConnectParams> params);
+  static void FinishOpen(std::unique_ptr<ConnectParams> params);
+  static void CreateConnection(std::unique_ptr<ConnectParams> params);
+
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  // |helper_| lives on the sequence |blocking_task_runner_| posts to and holds
+  // a weak reference back to the service that owns it.
+  std::unique_ptr<BlockingTaskHelper> helper_;
+  base::WeakPtrFactory<HidServiceFreeBSD> weak_factory_;
+
+  DISALLOW_COPY_AND_ASSIGN(HidServiceFreeBSD);
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_SERVICE_FREEBSD_H_
