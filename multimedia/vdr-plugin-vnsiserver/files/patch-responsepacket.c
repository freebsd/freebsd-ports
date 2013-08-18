--- a/responsepacket.c
+++ b/responsepacket.c
@@ -31,8 +31,15 @@
 #include <arpa/inet.h>
 #include <stdlib.h>
 #include <string.h>
+#include <inttypes.h>
 
+#ifndef __FreeBSD__
 #include <asm/byteorder.h>
+#else
+#include <sys/endian.h>
+#define __be64_to_cpu be64toh
+#define __cpu_to_be64 htobe64
+#endif
 
 #include "responsepacket.h"
 #include "vnsicommand.h"
