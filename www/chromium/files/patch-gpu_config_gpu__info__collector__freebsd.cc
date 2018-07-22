--- gpu/config/gpu_info_collector_freebsd.cc.orig	2018-07-20 13:47:10.021258000 +0200
+++ gpu/config/gpu_info_collector_freebsd.cc	2018-07-20 15:44:42.380444000 +0200
@@ -0,0 +1,20 @@
+// Copyright 2017 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "gpu/config/gpu_info_collector.h"
+
+namespace gpu {
+
+bool CollectContextGraphicsInfo(GPUInfo* gpu_info) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+bool CollectBasicGraphicsInfo(GPUInfo* gpu_info) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+
+}  // namespace gpu
