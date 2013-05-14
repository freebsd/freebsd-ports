--- /dev/null	2013-05-08 01:24:05.000000000 +0300
+++ chrome/browser/extensions/api/system_info_storage/storage_info_provider_bsd.cc	2013-05-08 01:20:01.000000000 +0300
@@ -0,0 +1,39 @@
+// Copyright 2013 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "chrome/browser/extensions/api/system_info_storage/storage_info_provider.h"
+
+namespace extensions {
+
+namespace {
+
+using api::experimental_system_info_storage::StorageUnitInfo;
+
+class StorageInfoProviderBSD : public StorageInfoProvider {
+ public:
+  StorageInfoProviderBSD() {}
+
+  virtual bool QueryInfo(StorageInfo* info) OVERRIDE {
+    NOTIMPLEMENTED();
+    return false;
+  }
+  virtual bool QueryUnitInfo(const std::string& id,
+                             StorageUnitInfo* info) OVERRIDE {
+    NOTIMPLEMENTED();
+    return false;
+  }
+
+ private:
+  virtual ~StorageInfoProviderBSD() {}
+};
+
+}  //
+
+// static
+StorageInfoProvider* StorageInfoProvider::Get() {
+  return StorageInfoProvider::GetInstance<StorageInfoProviderBSD>();
+}
+
+}  // namespace extensions
+
