--- content/browser/renderer_host/render_process_host_impl.cc.orig	2015-10-14 23:20:02.027419000 +0200
+++ content/browser/renderer_host/render_process_host_impl.cc	2015-10-14 23:20:29.597226000 +0200
@@ -38,6 +38,7 @@
 #include "base/tracked_objects.h"
 #include "cc/base/switches.h"
 #include "components/tracing/tracing_switches.h"
+#include "content/common/bluetooth/bluetooth_scan_filter.h"
 #include "content/browser/appcache/appcache_dispatcher_host.h"
 #include "content/browser/appcache/chrome_appcache_service.h"
 #include "content/browser/background_sync/background_sync_service_impl.h"
