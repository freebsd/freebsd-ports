--- gpu/config/gpu_info_collector_freebsd.cc.orig	2018-03-26 13:34:20.147630000 +0200
+++ gpu/config/gpu_info_collector_freebsd.cc	2018-03-26 13:35:09.089367000 +0200
@@ -0,0 +1,28 @@
+// Copyright 2017 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "gpu/config/gpu_info_collector.h"
+
+namespace gpu {
+
+CollectInfoResult CollectContextGraphicsInfo(GPUInfo* gpu_info) {
+  NOTIMPLEMENTED();
+  return kCollectInfoFatalFailure;
+}
+
+CollectInfoResult CollectBasicGraphicsInfo(GPUInfo* gpu_info) {
+  NOTIMPLEMENTED();
+  return kCollectInfoFatalFailure;
+}
+
+CollectInfoResult CollectDriverInfoGL(GPUInfo* gpu_info) {
+  NOTIMPLEMENTED();
+  return kCollectInfoFatalFailure;
+}
+
+void MergeGPUInfo(GPUInfo* basic_gpu_info, const GPUInfo& context_gpu_info) {
+  MergeGPUInfoGL(basic_gpu_info, context_gpu_info);
+}
+
+}  // namespace gpu
