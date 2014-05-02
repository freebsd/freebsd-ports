--- ./components/storage_monitor/storage_monitor_freebsd.h.orig	2014-04-24 23:23:44.000000000 +0200
+++ ./components/storage_monitor/storage_monitor_freebsd.h	2014-04-24 23:23:44.000000000 +0200
@@ -0,0 +1,43 @@
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
+#include "base/basictypes.h"
+#include "base/compiler_specific.h"
+#include "base/files/file_path.h"
+#include "base/files/file_path_watcher.h"
+#include "base/memory/scoped_ptr.h"
+#include "base/memory/weak_ptr.h"
+#include "components/storage_monitor/storage_monitor.h"
+#include "content/public/browser/browser_thread.h"
+
+class StorageMonitorFreeBSD : public StorageMonitor {
+ public:
+  // Should only be called by browser start up code.
+  // Use StorageMonitor::GetInstance() instead.
+  explicit StorageMonitorFreeBSD();
+  virtual ~StorageMonitorFreeBSD();
+
+  // Must be called for StorageMonitorFreeBSD to work.
+  virtual void Init() OVERRIDE;
+ private:
+  // StorageMonitor implementation.
+  virtual bool GetStorageInfoForPath(const base::FilePath& path,
+                                     StorageInfo* device_info) const OVERRIDE;
+
+  DISALLOW_COPY_AND_ASSIGN(StorageMonitorFreeBSD);
+};
+
+#endif  // COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
