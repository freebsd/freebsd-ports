--- content/browser/geolocation/wifi_data_provider_freebsd.h.orig	2016-05-20 17:18:26 UTC
+++ content/browser/geolocation/wifi_data_provider_freebsd.h
@@ -0,0 +1,30 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef CONTENT_BROWSER_GEOLOCATION_WIFI_DATA_PROVIDER_FREEBSD_H_
+#define CONTENT_BROWSER_GEOLOCATION_WIFI_DATA_PROVIDER_FREEBSD_H_
+
+#include "base/compiler_specific.h"
+#include "content/browser/geolocation/wifi_data_provider_common.h"
+#include "content/common/content_export.h"
+
+namespace content {
+
+class CONTENT_EXPORT WifiDataProviderFreeBSD : public WifiDataProviderCommon {
+ public:
+  WifiDataProviderFreeBSD();
+
+ private:
+  virtual ~WifiDataProviderFreeBSD();
+
+  // WifiDataProviderCommon
+  virtual WlanApiInterface* NewWlanApi() override;
+  virtual WifiPollingPolicy* NewPollingPolicy() override;
+
+  DISALLOW_COPY_AND_ASSIGN(WifiDataProviderFreeBSD);
+};
+
+}  // namespace content
+
+#endif  // CONTENT_BROWSER_GEOLOCATION_WIFI_DATA_PROVIDER_FREEBSD_H_
