--- services/device/hid/hid_service_freebsd.cc.orig	2020-07-18 19:40:14.415772000 -0700
+++ services/device/hid/hid_service_freebsd.cc	2020-07-21 20:00:55.322907000 -0700
@@ -0,0 +1,382 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_service_freebsd.h"
+
+#include <dev/usb/usb_ioctl.h>
+#include <stdint.h>
+#include <sys/socket.h>
+#include <sys/un.h>
+
+#include <set>
+#include <string>
+#include <vector>
+
+#include "base/bind.h"
+#include "base/files/file_descriptor_watcher_posix.h"
+#include "base/files/file_enumerator.h"
+#include "base/files/file_util.h"
+#include "base/files/file.h"
+#include "base/location.h"
+#include "base/logging.h"
+#include "base/posix/eintr_wrapper.h"
+#include "base/single_thread_task_runner.h"
+#include "base/stl_util.h"
+#include "base/strings/pattern.h"
+#include "base/strings/stringprintf.h"
+#include "base/strings/sys_string_conversions.h"
+#include "base/strings/string_util.h"
+#include "base/strings/string_split.h"
+#include "base/task/post_task.h"
+#include "base/threading/scoped_blocking_call.h"
+#include "base/threading/thread_task_runner_handle.h"
+#include "components/device_event_log/device_event_log.h"
+#include "services/device/hid/hid_connection_freebsd.h"
+
+const int kMaxPermissionChecks = 5;
+
+namespace device {
+
+struct HidServiceFreeBSD::ConnectParams {
+  ConnectParams(scoped_refptr<HidDeviceInfo> device_info,
+                ConnectCallback callback)
+      : device_info(std::move(device_info)),
+        callback(std::move(callback)),
+        task_runner(base::ThreadTaskRunnerHandle::Get()),
+        blocking_task_runner(
+            base::ThreadPool::CreateSequencedTaskRunner(kBlockingTaskTraits)) {}
+  ~ConnectParams() {}
+
+  scoped_refptr<HidDeviceInfo> device_info;
+  ConnectCallback callback;
+  scoped_refptr<base::SequencedTaskRunner> task_runner;
+  scoped_refptr<base::SequencedTaskRunner> blocking_task_runner;
+  base::ScopedFD fd;
+};
+
+class HidServiceFreeBSD::BlockingTaskRunnerHelper {
+ public:
+  BlockingTaskRunnerHelper(base::WeakPtr<HidServiceFreeBSD> service)
+      : service_(std::move(service)),
+        task_runner_(base::ThreadTaskRunnerHandle::Get()) {
+    DETACH_FROM_SEQUENCE(sequence_checker_);
+
+    timer_.reset(new base::RepeatingTimer());
+    devd_buffer_ = new net::IOBufferWithSize(1024);
+  }
+
+  ~BlockingTaskRunnerHelper() {
+  }
+
+  void Start() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+    const base::FilePath kDevRoot("/dev");
+    const std::string kUHIDPattern("/dev/uhid*");
+
+    base::FileEnumerator enumerator(kDevRoot, false, base::FileEnumerator::FILES);
+    do {
+      const base::FilePath next_device_path(enumerator.Next());
+      const std::string next_device = next_device_path.value();
+      if (next_device.empty())
+        break;
+
+      if (base::MatchPattern(next_device, kUHIDPattern))
+        OnDeviceAdded(next_device.substr(5));
+    } while (true);
+
+    SetupDevdMonitor();
+
+    task_runner_->PostTask(
+        FROM_HERE,
+        base::Bind(&HidServiceFreeBSD::FirstEnumerationComplete, service_));
+  }
+
+  bool HaveReadWritePermissions(std::string device_id) {
+    std::string device_node = "/dev/" + device_id;
+    base::internal::AssertBlockingAllowed();
+
+    base::FilePath device_path(device_node);
+    base::File device_file;
+    int flags =
+        base::File::FLAG_OPEN | base::File::FLAG_READ | base::File::FLAG_WRITE;
+    device_file.Initialize(device_path, flags);
+    if (!device_file.IsValid())
+      return false;
+
+    return true;
+  }
+
+  void OnDeviceAdded(std::string device_id) {
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+    std::string device_node = "/dev/" + device_id;
+    uint16_t vendor_id = 0xffff;
+    uint16_t product_id = 0xffff;
+    std::string product_name = "";
+    std::string serial_number = "";
+
+    std::vector<uint8_t> report_descriptor;
+
+    base::internal::AssertBlockingAllowed();
+
+    base::FilePath device_path(device_node);
+    base::File device_file;
+    int flags =
+        base::File::FLAG_OPEN | base::File::FLAG_READ | base::File::FLAG_WRITE;
+    device_file.Initialize(device_path, flags);
+    if (!device_file.IsValid()) {
+      HID_LOG(ERROR) << "Failed to open '" << device_node
+                     << "': "
+                     << base::File::ErrorToString(device_file.error_details());
+      return;
+    }
+
+    base::ScopedFD fd;
+    fd.reset(device_file.TakePlatformFile());
+
+    struct usb_gen_descriptor ugd;
+    ugd.ugd_data = NULL;
+    ugd.ugd_maxlen = 0xffff;
+    int result = HANDLE_EINTR(
+        ioctl(fd.get(), USB_GET_REPORT_DESC, &ugd));
+
+    if (result < 0) {
+      HID_LOG(ERROR) << "Failed to get report descriptor size";
+      return;
+    }
+
+    report_descriptor.resize(ugd.ugd_actlen);
+
+    ugd.ugd_data = report_descriptor.data();
+    ugd.ugd_maxlen = ugd.ugd_actlen;
+    result = HANDLE_EINTR(
+        ioctl(fd.get(), USB_GET_REPORT_DESC, &ugd));
+
+    if (result < 0) {
+      HID_LOG(ERROR) << "Failed to get report descriptor";
+      return;
+    }
+
+    scoped_refptr<HidDeviceInfo> device_info(new HidDeviceInfo(
+        device_id,
+        /*physical_device_id*/"",
+	vendor_id,
+	product_id,
+	product_name,
+	serial_number,
+        device::mojom::HidBusType::kHIDBusTypeUSB,
+        report_descriptor,
+	device_node));
+
+    task_runner_->PostTask(FROM_HERE, base::BindOnce(&HidServiceFreeBSD::AddDevice,
+                                                 service_, device_info));
+  }
+
+  void OnDeviceRemoved(std::string device_id) {
+    base::ScopedBlockingCall scoped_blocking_call(
+        FROM_HERE, base::BlockingType::MAY_BLOCK);
+    task_runner_->PostTask(
+        FROM_HERE, base::Bind(&HidServiceFreeBSD::RemoveDevice, service_,
+                              device_id));
+  }
+
+ private:
+
+  void CheckPendingPermissionChange() {
+    base::internal::AssertBlockingAllowed();
+    std::map<std::string, int>::iterator it;
+    for (it = permissions_checks_attempts_.begin(); it != permissions_checks_attempts_.end();) {
+      std::string device_name = it->first;
+      bool keep = true;
+      if (HaveReadWritePermissions(device_name)) {
+        OnDeviceAdded(device_name);
+        keep = false;
+      }
+      else if (it->second-- <= 0) {
+        HID_LOG(ERROR) << "Still don't have write permissions to '" << device_name
+                       << "' after " << kMaxPermissionChecks << " attempts";
+        keep = false;
+      }
+
+      if (keep)
+        ++it;
+      else
+        permissions_checks_attempts_.erase(it++);
+    }
+
+    if (permissions_checks_attempts_.empty())
+      timer_->Stop();
+  }
+
+  void SetupDevdMonitor() {
+    base::internal::AssertBlockingAllowed();
+
+    int devd_fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
+    if (devd_fd < 0)
+      return;
+
+    struct sockaddr_un sa;
+
+    sa.sun_family = AF_UNIX;
+    strlcpy(sa.sun_path, "/var/run/devd.seqpacket.pipe", sizeof(sa.sun_path));
+    if (connect(devd_fd, (struct sockaddr *) &sa, sizeof(sa)) < 0) {
+      close(devd_fd);
+      return;
+    } 
+
+    devd_fd_.reset(devd_fd);
+    file_watcher_ = base::FileDescriptorWatcher::WatchReadable(
+        devd_fd_.get(), base::Bind(&BlockingTaskRunnerHelper::OnDevdMessageCanBeRead,
+                                   base::Unretained(this)));
+  }
+
+  void OnDevdMessageCanBeRead() {
+    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+    ssize_t bytes_read = HANDLE_EINTR(recv(devd_fd_.get(), devd_buffer_->data(),
+                                      devd_buffer_->size() - 1, MSG_WAITALL));
+    if (bytes_read < 0) {
+      if (errno != EAGAIN) {
+        HID_LOG(ERROR) << "Read failed";
+        file_watcher_.reset();
+      }
+      return;
+    }
+
+    devd_buffer_->data()[bytes_read] = 0;
+    char *data = devd_buffer_->data();
+    // It may take some time for devd to change permissions
+    // on /dev/uhidX node. So do not fail immediately if
+    // open fail. Retry each second for kMaxPermissionChecks
+    // times before giving up entirely
+    if (base::StartsWith(data, "+uhid", base::CompareCase::SENSITIVE)) {
+      std::vector<std::string> parts = base::SplitString(
+        data, " ", base::TRIM_WHITESPACE, base::SPLIT_WANT_ALL);
+      if (!parts.empty()) {
+        std::string device_name = parts[0].substr(1); // skip '+'
+        if (HaveReadWritePermissions(device_name))
+          OnDeviceAdded(parts[0].substr(1));
+        else {
+          // Do not re-add to checks
+          if (permissions_checks_attempts_.find(device_name) == permissions_checks_attempts_.end()) {
+            permissions_checks_attempts_.insert(std::pair<std::string, int>(device_name, kMaxPermissionChecks));
+            timer_->Start(FROM_HERE, base::TimeDelta::FromSeconds(1),
+                          this, &BlockingTaskRunnerHelper::CheckPendingPermissionChange);
+          }
+        }
+      }
+    }
+
+    if (base::StartsWith(data, "-uhid", base::CompareCase::SENSITIVE)) {
+      std::vector<std::string> parts = base::SplitString(
+        data, " ", base::TRIM_WHITESPACE, base::SPLIT_WANT_ALL);
+      if (!parts.empty()) {
+        std::string device_name = parts[0].substr(1); // skip '-'
+        auto it = permissions_checks_attempts_.find(device_name);
+        if (it != permissions_checks_attempts_.end()) {
+          permissions_checks_attempts_.erase(it);
+          if (permissions_checks_attempts_.empty())
+            timer_->Stop();
+        }
+        OnDeviceRemoved(parts[0].substr(1));
+      }
+    }
+  }
+
+  SEQUENCE_CHECKER(sequence_checker_);
+
+  // This weak pointer is only valid when checked on this task runner.
+  base::WeakPtr<HidServiceFreeBSD> service_;
+  scoped_refptr<base::SequencedTaskRunner> task_runner_;
+  std::unique_ptr<base::FileDescriptorWatcher::Controller> file_watcher_;
+  std::unique_ptr<base::RepeatingTimer> timer_;
+  base::ScopedFD devd_fd_;
+  scoped_refptr<net::IOBufferWithSize> devd_buffer_;
+  std::map<std::string, int> permissions_checks_attempts_;
+
+  DISALLOW_COPY_AND_ASSIGN(BlockingTaskRunnerHelper);
+};
+
+HidServiceFreeBSD::HidServiceFreeBSD()
+    : blocking_task_runner_(
+          base::ThreadPool::CreateSequencedTaskRunner(kBlockingTaskTraits)),
+      helper_(nullptr, base::OnTaskRunnerDeleter(blocking_task_runner_)) {
+  helper_.reset(new BlockingTaskRunnerHelper(weak_factory_.GetWeakPtr()));
+  blocking_task_runner_->PostTask(
+      FROM_HERE,
+      base::BindOnce(&BlockingTaskRunnerHelper::Start, base::Unretained(helper_.get())));
+}
+
+HidServiceFreeBSD::~HidServiceFreeBSD() {
+  blocking_task_runner_->DeleteSoon(FROM_HERE, helper_.release());
+}
+
+base::WeakPtr<HidService> HidServiceFreeBSD::GetWeakPtr() {
+  return weak_factory_.GetWeakPtr();
+}
+
+// static
+void HidServiceFreeBSD::OpenOnBlockingThread(
+    std::unique_ptr<ConnectParams> params) {
+  base::ScopedBlockingCall scoped_blocking_call(
+      FROM_HERE, base::BlockingType::MAY_BLOCK);
+  scoped_refptr<base::SequencedTaskRunner> task_runner = params->task_runner;
+
+  base::FilePath device_path(params->device_info->device_node());
+  base::File device_file;
+  int flags =
+      base::File::FLAG_OPEN | base::File::FLAG_READ | base::File::FLAG_WRITE;
+  device_file.Initialize(device_path, flags);
+  if (!device_file.IsValid()) {
+    HID_LOG(EVENT) << "Failed to open '" << params->device_info->device_node()
+                   << "': "
+                   << base::File::ErrorToString(device_file.error_details());
+    task_runner->PostTask(FROM_HERE,
+		          base::BindOnce(std::move(params->callback), nullptr));
+    return;
+  }
+  params->fd.reset(device_file.TakePlatformFile());
+  task_runner->PostTask(FROM_HERE, base::BindOnce(&HidServiceFreeBSD::FinishOpen,
+			                          std::move(params)));
+}
+
+void HidServiceFreeBSD::Connect(const std::string& device_guid,
+                            ConnectCallback callback) {
+  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+
+  const auto& map_entry = devices().find(device_guid);
+  if (map_entry == devices().end()) {
+    base::ThreadTaskRunnerHandle::Get()->PostTask(
+        FROM_HERE, base::BindOnce(std::move(callback), nullptr));
+    return;
+  }
+
+  scoped_refptr<HidDeviceInfo> device_info = map_entry->second;
+
+  auto params = std::make_unique<ConnectParams>(device_info, std::move(callback));
+  scoped_refptr<base::SequencedTaskRunner> blocking_task_runner =
+      params->blocking_task_runner;
+
+  blocking_task_runner->PostTask(
+      FROM_HERE, base::BindOnce(&HidServiceFreeBSD::OpenOnBlockingThread,
+                                std::move(params)));
+}
+
+// static
+void HidServiceFreeBSD::FinishOpen(std::unique_ptr<ConnectParams> params) {
+  DCHECK(params->fd.is_valid());
+
+  if (!base::SetNonBlocking(params->fd.get())) {
+    HID_PLOG(ERROR) << "Failed to set the non-blocking flag on the device fd";
+    std::move(params->callback).Run(nullptr);
+  }
+
+  std::move(params->callback).Run(base::MakeRefCounted<HidConnectionFreeBSD>(
+    std::move(params->device_info),
+    std::move(params->fd),
+    std::move(params->blocking_task_runner)
+  ));
+}
+
+}  // namespace device
