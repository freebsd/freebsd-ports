--- src/sflowtool.c.orig	2023-03-23 17:36:24 UTC
+++ src/sflowtool.c
@@ -29,13 +29,21 @@ extern "C" {
 #include <inttypes.h>
 #include <arpa/inet.h>
 #include <netdb.h>
-#include <byteswap.h>
+#include <sys/endian.h>
 #include <getopt.h>
 
 #include "sflow.h" /* sFlow v5 */
 #include "sflow_v2v4.h" /* sFlow v2/4 */
 #include "assert.h"
 #include "sflow_xdr.h" /* sFlow encode */
+
+#define __bswap_16(x) __bswap16(x)
+#define __bswap_32(x) __bswap32(x)
+#define __bswap_64(x) __bswap64(x)
+
+#define bswap_16(x) __bswap16(x)
+#define bswap_32(x) __bswap32(x)
+#define bswap_64(x) __bswap64(x)
 
 #define SPOOFSOURCE 1
 #define YES 1
