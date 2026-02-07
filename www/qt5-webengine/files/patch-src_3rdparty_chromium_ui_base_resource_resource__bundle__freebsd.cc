--- src/3rdparty/chromium/ui/base/resource/resource_bundle_freebsd.cc.orig	2019-07-08 11:29:35 UTC
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle_freebsd.cc
@@ -0,0 +1,21 @@
+// Copyright 2017 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "ui/base/resource/resource_bundle.h"
+
+#include "base/logging.h"
+#include "base/macros.h"
+#include "ui/gfx/image/image.h"
+
+namespace ui {
+
+void ResourceBundle::LoadCommonResources() {
+  LoadChromeResources();
+}
+
+gfx::Image& ResourceBundle::GetNativeImageNamed(int resource_id) {
+  return GetImageNamed(resource_id);
+}
+
+}  // namespace ui
