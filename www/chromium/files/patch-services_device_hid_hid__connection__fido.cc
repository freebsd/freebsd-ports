--- services/device/hid/hid_connection_fido.cc.orig	2022-06-17 14:20:10 UTC
+++ services/device/hid/hid_connection_fido.cc
@@ -0,0 +1,197 @@
+// Copyright (c) 2020 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_connection_fido.h"
+
+#include "base/bind.h"
+#include "base/files/file_descriptor_watcher_posix.h"
+#include "base/location.h"
+#include "base/numerics/safe_math.h"
+#include "base/posix/eintr_wrapper.h"
+#include "base/task/single_thread_task_runner.h"
+#include "base/threading/scoped_blocking_call.h"
+#include "base/threading/thread_restrictions.h"
+#include "base/threading/thread_task_runner_handle.h"
+#include "components/device_event_log/device_event_log.h"
+#include "services/device/hid/hid_service.h"
+
+namespace device {
+
+class HidConnectionFido::BlockingTaskHelper {
+public:
+  BlockingTaskHelper(base::ScopedFD fd,
+                     scoped_refptr<HidDeviceInfo> device_info,
+                     base::WeakPtr<HidConnectionFido> connection)
+      : fd_(std::move(fd)),
+        // Report buffers must always have room for the report ID.
+        report_buffer_size_(device_info->max_input_report_size() + 1),
+        has_report_id_(device_info->has_report_id()), connection_(connection),
+        origin_task_runner_(base::ThreadTaskRunnerHandle::Get()) {
+    DETACH_FROM_SEQUENCE(sequence_checker_);
+  }
+
+  BlockingTaskHelper(const BlockingTaskHelper&) = delete;
+  BlockingTaskHelper& operator=(const BlockingTaskHelper&) = delete;
+
+  ~BlockingTaskHelper() { DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_); }
+
+  // Starts the FileDescriptorWatcher that reads input events from the device.
+  // Must be called on a thread that has a base::MessageLoopForIO.
+  void Start() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::internal::AssertBlockingAllowed();
+
+    file_watcher_ = base::FileDescriptorWatcher::WatchReadable(
+        fd_.get(), base::BindRepeating(&BlockingTaskHelper::OnFileCanReadWithoutBlocking,
+                              base::Unretained(this)));
+  }
+
+  void Write(scoped_refptr<base::RefCountedBytes> buffer,
+             WriteCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+
+    auto data = buffer->front();
+    size_t size = buffer->size();
+    // if report id is 0, it shouldn't be included
+    if (data[0] == 0) {
+      data++;
+      size--;
+    }
+
+    ssize_t result = HANDLE_EINTR(write(fd_.get(), data, size));
+    bool success = static_cast<size_t>(result) == size;
+    if (!success) {
+      HID_LOG(EVENT) << "HID write failed: " << result << " != " << size;
+    }
+    origin_task_runner_->PostTask(FROM_HERE,
+                                  base::BindOnce(std::move(callback), success));
+  }
+
+  void GetFeatureReport(uint8_t report_id,
+                        scoped_refptr<base::RefCountedBytes> buffer,
+                        ReadCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+    HID_PLOG(EVENT) << "GendFeatureReport not implemented on OpenBSD";
+    origin_task_runner_->PostTask(
+        FROM_HERE, base::BindOnce(std::move(callback), false, nullptr, 0));
+  }
+
+  void SendFeatureReport(scoped_refptr<base::RefCountedBytes> buffer,
+                         WriteCallback callback) {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    HID_PLOG(EVENT) << "SendFeatureReport not implemented on OpenBSD";
+    origin_task_runner_->PostTask(FROM_HERE,
+                                  base::BindOnce(std::move(callback), false));
+  }
+
+private:
+  void OnFileCanReadWithoutBlocking() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+    scoped_refptr<base::RefCountedBytes> buffer(
+        new base::RefCountedBytes(report_buffer_size_));
+    unsigned char *data = buffer->front();
+    size_t length = report_buffer_size_;
+    if (!has_report_id_) {
+      // OpenBSD will not prefix the buffer with a report ID if report IDs are
+      // not used by the device. Prefix the buffer with 0.
+      *data++ = 0;
+      length--;
+    }
+
+    ssize_t bytes_read = HANDLE_EINTR(read(fd_.get(), data, length));
+    if (bytes_read < 0) {
+      if (errno != EAGAIN) {
+        HID_PLOG(EVENT) << "Read failed";
+        // This assumes that the error is unrecoverable and disables reading
+        // from the device until it has been re-opened.
+        // TODO(reillyg): Investigate starting and stopping the file descriptor
+        // watcher in response to pending read requests so that per-request
+        // errors can be returned to the client.
+        file_watcher_.reset();
+      }
+      return;
+    }
+    if (!has_report_id_) {
+      // Behave as if the byte prefixed above as the the report ID was read.
+      bytes_read++;
+    }
+
+    origin_task_runner_->PostTask(
+        FROM_HERE, base::BindOnce(&HidConnectionFido::ProcessInputReport,
+                                  connection_, buffer, bytes_read));
+  }
+
+  SEQUENCE_CHECKER(sequence_checker_);
+  base::ScopedFD fd_;
+  const size_t report_buffer_size_;
+  const bool has_report_id_;
+  base::WeakPtr<HidConnectionFido> connection_;
+  const scoped_refptr<base::SequencedTaskRunner> origin_task_runner_;
+  std::unique_ptr<base::FileDescriptorWatcher::Controller> file_watcher_;
+};
+
+HidConnectionFido::HidConnectionFido(
+    scoped_refptr<HidDeviceInfo> device_info, base::ScopedFD fd,
+    scoped_refptr<base::SequencedTaskRunner> blocking_task_runner,
+    bool allow_protected_reports, bool allow_fido_reports)
+    : HidConnection(device_info, allow_protected_reports, allow_fido_reports),
+      blocking_task_runner_(std::move(blocking_task_runner)),
+      weak_factory_(this),
+      helper_(std::make_unique<BlockingTaskHelper>(
+          std::move(fd), device_info, weak_factory_.GetWeakPtr())) {
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskHelper::Start,
+                                base::Unretained(helper_.get())));
+}
+
+HidConnectionFido::~HidConnectionFido() = default;
+
+void HidConnectionFido::PlatformClose() {
+  // By closing the device on the blocking task runner 1) the requirement that
+  // base::ScopedFD is destroyed on a thread where I/O is allowed is satisfied
+  // and 2) any tasks posted to this task runner that refer to this file will
+  // complete before it is closed.
+  blocking_task_runner_->DeleteSoon(FROM_HERE, helper_.release());
+}
+
+void HidConnectionFido::PlatformWrite(
+    scoped_refptr<base::RefCountedBytes> buffer, WriteCallback callback) {
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskHelper::Write,
+                                base::Unretained(helper_.get()), buffer,
+                                std::move(callback)));
+}
+
+void HidConnectionFido::PlatformGetFeatureReport(uint8_t report_id,
+                                                 ReadCallback callback) {
+  // The first byte of the destination buffer is the report ID being requested
+  // and is overwritten by the feature report.
+  DCHECK_GT(device_info()->max_feature_report_size(), 0u);
+  scoped_refptr<base::RefCountedBytes> buffer(
+      new base::RefCountedBytes(device_info()->max_feature_report_size() + 1));
+  if (report_id != 0)
+    buffer->data()[0] = report_id;
+
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskHelper::GetFeatureReport,
+                                base::Unretained(helper_.get()), report_id,
+                                buffer, std::move(callback)));
+}
+
+void HidConnectionFido::PlatformSendFeatureReport(
+    scoped_refptr<base::RefCountedBytes> buffer, WriteCallback callback) {
+  base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
+                                                base::BlockingType::MAY_BLOCK);
+  blocking_task_runner_->PostTask(
+      FROM_HERE, base::BindOnce(&BlockingTaskHelper::SendFeatureReport,
+                                base::Unretained(helper_.get()), buffer,
+                                std::move(callback)));
+}
+
+} // namespace device
