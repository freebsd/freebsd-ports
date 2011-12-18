--- a/src/net/responsepacket.c
+++ b/src/net/responsepacket.c
@@ -31,7 +31,12 @@
 #include <arpa/inet.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __cpu_to_be64 htobe64
+#else
 #include <asm/byteorder.h>
+#endif
 #include <zlib.h>
 
 #include "config/config.h"
