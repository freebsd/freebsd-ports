--- src/lib/protocols/quic.c.orig	2019-03-01 17:04:18 UTC
+++ src/lib/protocols/quic.c
@@ -22,6 +22,10 @@
  *
  */
 
+#if defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
+#include <sys/endian.h>
+#endif
+
 #include "ndpi_protocol_ids.h"
 
 #define NDPI_CURRENT_PROTO NDPI_PROTOCOL_QUIC
