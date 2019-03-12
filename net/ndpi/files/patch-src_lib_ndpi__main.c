--- src/lib/ndpi_main.c.orig	2019-03-01 17:04:18 UTC
+++ src/lib/ndpi_main.c
@@ -41,6 +41,10 @@
 #include <unistd.h>
 #endif
 
+#if defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
+#include <sys/endian.h>
+#endif
+
 #include "ndpi_content_match.c.inc"
 #include "third_party/include/ndpi_patricia.h"
 #include "third_party/include/ht_hash.h"
