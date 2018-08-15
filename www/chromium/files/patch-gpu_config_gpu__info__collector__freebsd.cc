--- gpu/config/gpu_info_collector_freebsd.cc.orig	2018-08-13 21:50:38.978048000 +0200
+++ gpu/config/gpu_info_collector_freebsd.cc	2018-08-13 21:54:59.868827000 +0200
@@ -0,0 +1,29 @@
+// Copyright 2017 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/trace_event/trace_event.h"
+#include "gpu/config/gpu_info_collector.h"
+#include "third_party/angle/src/gpu_info_util/SystemInfo.h"
+
+namespace gpu {
+
+bool CollectContextGraphicsInfo(GPUInfo* gpu_info) {
+  DCHECK(gpu_info);
+
+  TRACE_EVENT0("gpu", "gpu_info_collector::CollectGraphicsInfo");
+
+  return CollectGraphicsInfoGL(gpu_info);
+}
+
+bool CollectBasicGraphicsInfo(GPUInfo* gpu_info) {
+  DCHECK(gpu_info);
+
+  angle::SystemInfo system_info;
+  bool success = angle::GetSystemInfo(&system_info);
+  FillGPUInfoFromSystemInfo(gpu_info, &system_info);
+  return success;
+}
+
+
+}  // namespace gpu
