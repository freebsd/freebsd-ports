--- base/threading/platform_thread_bsd.cc.orig	2026-01-16 14:21:21 UTC
+++ base/threading/platform_thread_bsd.cc
@@ -0,0 +1,39 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+// Description: These are stubs for *BSD.
+
+#include "base/notimplemented.h"
+#include "base/threading/platform_thread.h"
+
+namespace base {
+namespace internal {
+
+void SetCurrentThreadTypeImpl(ThreadType thread_type,
+                              MessagePumpType pump_type_hint) {
+  NOTIMPLEMENTED();
+  return;
+}
+
+bool CanSetThreadTypeToRealtimeAudio() {
+  return false;
+}
+
+PlatformPriorityOverride SetThreadTypeOverride(
+    PlatformThreadHandle thread_handle,
+    ThreadType thread_type) {
+  return false;
+}
+
+void RemoveThreadTypeOverrideImpl(
+    const PlatformPriorityOverride& priority_override_handle,
+    ThreadType thread_type) {}
+
+}  // namespace internal
+
+// static
+void PlatformThreadBase::SetName(const std::string& name) {
+  SetNameCommon(name);
+}
+
+}  // namespace base
