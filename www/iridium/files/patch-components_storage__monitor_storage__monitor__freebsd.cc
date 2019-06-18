--- components/storage_monitor/storage_monitor_freebsd.cc.orig	2019-03-17 01:47:13 UTC
+++ components/storage_monitor/storage_monitor_freebsd.cc
@@ -0,0 +1,54 @@
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
