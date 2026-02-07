--- include/lttng/ust-tracepoint-event.h.orig	2022-03-25 15:37:17 UTC
+++ include/lttng/ust-tracepoint-event.h
@@ -14,6 +14,11 @@
 #include <lttng/ust-arch.h>
 #include <lttng/ust-compiler.h>
 #include <lttng/tracepoint.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define NT_GNU_BUILD_ID 3
+#endif
 #include <lttng/ust-endian.h>
 #include <lttng/ust-api-compat.h>
 #include <string.h>
@@ -1033,6 +1038,7 @@ void lttng_ust__event_probe__##_provider##___##_name(L
 
 /* Reset all macros within LTTNG_UST_TRACEPOINT_EVENT */
 #include <lttng/ust-tracepoint-event-reset.h>
+#include <lttng/ust-events.h>
 
 /*
  * Declare _loglevel___##__provider##___##__name as non-static, with
