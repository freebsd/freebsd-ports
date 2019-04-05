--- third_party/crashpad/crashpad/client/crashpad_client_posix.cc.orig	2019-03-17 01:47:14 UTC
+++ third_party/crashpad/crashpad/client/crashpad_client_posix.cc
@@ -0,0 +1,38 @@
+// Copyright 2017 The Crashpad Authors. All rights reserved.
+//
+// Licensed under the Apache License, Version 2.0 (the "License");
+// you may not use this file except in compliance with the License.
+// You may obtain a copy of the License at
+//
+//     http://www.apache.org/licenses/LICENSE-2.0
+//
+// Unless required by applicable law or agreed to in writing, software
+// distributed under the License is distributed on an "AS IS" BASIS,
+// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+// See the License for the specific language governing permissions and
+// limitations under the License.
+
+#include "client/crashpad_client.h"
+
+#include "base/logging.h"
+
+namespace crashpad {
+
+CrashpadClient::CrashpadClient() {}
+
+CrashpadClient::~CrashpadClient() {}
+
+bool CrashpadClient::StartHandler(
+    const base::FilePath& handler,
+    const base::FilePath& database,
+    const base::FilePath& metrics_dir,
+    const std::string& url,
+    const std::map<std::string, std::string>& annotations,
+    const std::vector<std::string>& arguments,
+    bool restartable,
+    bool asynchronous_start) {
+  NOTREACHED();  // TODO(scottmg): https://crashpad.chromium.org/bug/196
+  return false;
+}
+
+}  // namespace crashpad
