--- ./content/browser/geolocation/wifi_data_provider_freebsd.h.orig	2014-08-22 15:06:25.000000000 +0200
+++ ./content/browser/geolocation/wifi_data_provider_freebsd.h	2014-08-22 15:06:25.000000000 +0200
@@ -0,0 +1,31 @@
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
+// Implementation of the wifi data provider for FreeBSD.
+class CONTENT_EXPORT FreeBSDWifiDataProvider : public WifiDataProviderCommon {
+public:
+	FreeBSDWifiDataProvider();
+
+private:
+	virtual ~FreeBSDWifiDataProvider();
+
+	// WifiDataProviderCommon
+	virtual WlanApiInterface* NewWlanApi() OVERRIDE;
+	virtual WifiPollingPolicy* NewPollingPolicy() OVERRIDE;
+
+	DISALLOW_COPY_AND_ASSIGN(FreeBSDWifiDataProvider);
+};
+
+} // namespace content
+
+#endif  // CONTENT_BROWSER_GEOLOCATION_WIFI_DATA_PROVIDER_FREEBSD_H_
