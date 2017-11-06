--- include/lttng/ust-tracepoint-event.h.orig	2016-11-29 01:46:24 UTC
+++ include/lttng/ust-tracepoint-event.h
@@ -28,7 +28,19 @@
 #include <lttng/ringbuffer-config.h>
 #include <lttng/ust-compiler.h>
 #include <lttng/tracepoint.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#define __bswap_16 bswap16
+#define __bswap_32 bswap32
+#define __bswap_64 bswap64
+#define NT_GNU_BUILD_ID 3
+#else
 #include <byteswap.h>
+#endif
 #include <string.h>
 
 #define __LTTNG_UST_NULL_STRING	"(null)"
@@ -941,6 +950,7 @@ static const struct lttng_event_desc __e
 
 /* Reset all macros within TRACEPOINT_EVENT */
 #include <lttng/ust-tracepoint-event-reset.h>
+#include <lttng/ust-events.h>
 
 #undef TRACEPOINT_EVENT_INSTANCE
 #define TRACEPOINT_EVENT_INSTANCE(_provider, _template, _name, _args)	       \
