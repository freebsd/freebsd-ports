--- ui/base/resource/resource_bundle_freebsd.cc.orig	2017-09-08 18:23:28.279481000 +0200
+++ ui/base/resource/resource_bundle_freebsd.cc	2017-09-08 18:23:04.528326000 +0200
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
