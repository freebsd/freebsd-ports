--- a/requestpacket.c
+++ b/requestpacket.c
@@ -28,7 +28,13 @@
 #include <stdint.h>
 #include <string.h>
 
+#ifndef __FreeBSD__
 #include <asm/byteorder.h>
+#else
+#include <sys/endian.h>
+#define __be64_to_cpu be64toh
+#define __cpu_to_be64 htobe64
+#endif
 
 #include "config.h"
 #include "requestpacket.h"
