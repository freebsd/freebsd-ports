--- components/storage_monitor/storage_monitor_freebsd.h.orig	2017-04-22 13:58:19 UTC
+++ components/storage_monitor/storage_monitor_freebsd.h
@@ -0,0 +1,45 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// StorageMonitorFreeBSD processes mount point change events, notifies listeners
+// about the addition and deletion of media devices, and answers queries about
+// mounted devices.
+// StorageMonitorFreeBSD lives on the UI thread, and uses ???
+// the FILE thread to get mount point change events.
+
+#ifndef COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
+#define COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
+
+#include <map>
+#include <string>
+
+#include "base/compiler_specific.h"
+#include "base/files/file_path.h"
+#include "base/files/file_path_watcher.h"
+#include "base/memory/weak_ptr.h"
+#include "components/storage_monitor/storage_monitor.h"
+#include "content/public/browser/browser_thread.h"
+
+namespace storage_monitor {
+
+class StorageMonitorFreeBSD : public StorageMonitor {
+ public:
+  // Should only be called by browser start up code.
+  // Use StorageMonitor::GetInstance() instead.
+  explicit StorageMonitorFreeBSD();
+  virtual ~StorageMonitorFreeBSD();
+
+  // Must be called for StorageMonitorFreeBSD to work.
+  virtual void Init() override;
+ private:
+  // StorageMonitor implementation.
+  virtual bool GetStorageInfoForPath(const base::FilePath& path,
+                                     StorageInfo* device_info) const override;
+
+  DISALLOW_COPY_AND_ASSIGN(StorageMonitorFreeBSD);
+};
+
+} // namespace storage_monitor
+
+#endif  // COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
