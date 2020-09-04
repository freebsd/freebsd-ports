--- liblttng-ust-ctl/ustctl.c.orig	2016-11-29 01:46:24 UTC
+++ liblttng-ust-ctl/ustctl.c
@@ -23,7 +23,19 @@
 #include <lttng/ust-abi.h>
 #include <lttng/ust-events.h>
 #include <sys/mman.h>
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
 
 #include <usterr-signal-safe.h>
 #include <ust-comm.h>
@@ -76,7 +88,7 @@ extern void lttng_ring_buffer_client_discard_exit(void
 extern void lttng_ring_buffer_client_discard_rt_exit(void);
 extern void lttng_ring_buffer_metadata_client_exit(void);
 
-volatile enum ust_loglevel ust_loglevel;
+extern volatile enum ust_loglevel ust_loglevel;
 
 int ustctl_release_handle(int sock, int handle)
 {
