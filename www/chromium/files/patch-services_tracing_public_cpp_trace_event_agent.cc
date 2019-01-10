--- services/tracing/public/cpp/trace_event_agent.cc.orig	2019-01-09 13:13:48.962628000 +0100
+++ services/tracing/public/cpp/trace_event_agent.cc	2019-01-09 13:14:04.280587000 +0100
@@ -23,7 +23,7 @@
 #include "services/tracing/public/mojom/constants.mojom.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 #define PERFETTO_AVAILABLE
 #include "services/tracing/public/cpp/perfetto/producer_client.h"
 #include "services/tracing/public/cpp/perfetto/trace_event_data_source.h"
