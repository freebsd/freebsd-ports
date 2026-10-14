--- src/3rdparty/chromium/base/threading/platform_thread_bsd.cc.orig	2026-09-07 11:51:09 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_bsd.cc
@@ -0,0 +1,41 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+// Description: These are stubs for *BSD.
+
+#include "base/threading/platform_thread.h"
+#include "base/threading/platform_thread_internal_posix.h"
+
+namespace base {
+namespace internal {
+
+const ThreadPriorityToNiceValuePairForTest
+    kThreadPriorityToNiceValueMapForTest[7] = {
+        {ThreadPriorityForTest::kRealtimeAudio, -10},
+        {ThreadPriorityForTest::kDisplay, -8},
+        {ThreadPriorityForTest::kNormal, 0},
+        {ThreadPriorityForTest::kUtility, 2},
+        {ThreadPriorityForTest::kBackground, 10},
+};
+
+bool CanSetThreadTypeToRealtimeAudio() {
+  return false;
+}
+
+bool SetCurrentThreadTypeForPlatform(ThreadType thread_type,
+                                MessagePumpType pump_type_hint) {
+  return false;
+}
+
+std::optional<ThreadPriorityForTest>
+GetCurrentThreadPriorityForPlatformForTest() {
+  return std::nullopt;
+}
+}  // namespace internal
+
+// static
+void PlatformThreadBase::SetName(const std::string& name) {
+  SetNameCommon(name);
+}
+
+}  // namespace base
