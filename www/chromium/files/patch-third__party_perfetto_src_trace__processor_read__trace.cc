--- third_party/perfetto/src/trace_processor/read_trace.cc.orig	2021-04-14 18:43:06 UTC
+++ third_party/perfetto/src/trace_processor/read_trace.cc
@@ -33,7 +33,8 @@
 #include "protos/perfetto/trace/trace_packet.pbzero.h"
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #define PERFETTO_HAS_AIO_H() 1
 #else
 #define PERFETTO_HAS_AIO_H() 0
