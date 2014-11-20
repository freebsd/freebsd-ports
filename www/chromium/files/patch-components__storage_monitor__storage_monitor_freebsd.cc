--- components/storage_monitor/storage_monitor_freebsd.cc.orig	2014-10-13 17:11:08 UTC
+++ components/storage_monitor/storage_monitor_freebsd.cc
@@ -0,0 +1,102 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// StorageMonitorFreeBSD implementation.
+
+#include "components/storage_monitor/storage_monitor_freebsd.h"
+
+#include <stdio.h>
+
+#include <list>
+
+#include "base/basictypes.h"
+#include "base/bind.h"
+#include "base/metrics/histogram.h"
+#include "base/process/kill.h"
+#include "base/process/launch.h"
+#include "base/stl_util.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/strings/string_util.h"
+#include "base/strings/utf_string_conversions.h"
+#include "components/storage_monitor/media_storage_util.h"
+#include "components/storage_monitor/removable_device_constants.h"
+#include "components/storage_monitor/storage_info.h"
+
+using content::BrowserThread;
+
+namespace storage_monitor {
+
+namespace {
+
+// udev device property constants.
+const char kBlockSubsystemKey[] = "block";
+const char kDiskDeviceTypeKey[] = "disk";
+const char kFsUUID[] = "ID_FS_UUID";
+const char kLabel[] = "ID_FS_LABEL";
+const char kModel[] = "ID_MODEL";
+const char kModelID[] = "ID_MODEL_ID";
+const char kRemovableSysAttr[] = "removable";
+const char kSerialShort[] = "ID_SERIAL_SHORT";
+const char kSizeSysAttr[] = "size";
+const char kVendor[] = "ID_VENDOR";
+const char kVendorID[] = "ID_VENDOR_ID";
+
+StorageMonitor::EjectStatus EjectPathOnFileThread(
+    const base::FilePath& path,
+    const base::FilePath& device) {
+  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
+
+  static const char kUmountBinary[] = "/sbin/umount";
+  std::vector<std::string> command;
+  command.push_back(kUmountBinary);
+  command.push_back(path.value());
+
+  base::LaunchOptions options;
+  base::ProcessHandle handle;
+  if (!base::LaunchProcess(command, options, &handle))
+    return StorageMonitor::EJECT_FAILURE;
+
+  int exit_code = -1;
+  if (!base::WaitForExitCodeWithTimeout(handle, &exit_code,
+      base::TimeDelta::FromMilliseconds(3000))) {
+    base::KillProcess(handle, -1, false);
+    base::EnsureProcessTerminated(handle);
+    return StorageMonitor::EJECT_FAILURE;
+  }
+
+  // TODO(gbillock): Make sure this is found in documentation
+  // somewhere. Experimentally it seems to hold that exit code
+  // 1 means device is in use.
+  if (exit_code == 1)
+    return StorageMonitor::EJECT_IN_USE;
+  if (exit_code != 0)
+    return StorageMonitor::EJECT_FAILURE;
+
+  return StorageMonitor::EJECT_OK;
+}
+
+}  // namespace
+
+StorageMonitorFreeBSD::StorageMonitorFreeBSD() {
+  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
+}
+
+StorageMonitorFreeBSD::~StorageMonitorFreeBSD() {
+  DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
+}
+
+void StorageMonitorFreeBSD::Init() {
+}
+
+bool StorageMonitorFreeBSD::GetStorageInfoForPath(
+    const base::FilePath& path,
+    StorageInfo* device_info) const {
+  return false; // TODO
+}
+
+StorageMonitor* StorageMonitor::CreateInternal() {
+  return new StorageMonitorFreeBSD();
+}
+
+} // namespace storage_monitor
