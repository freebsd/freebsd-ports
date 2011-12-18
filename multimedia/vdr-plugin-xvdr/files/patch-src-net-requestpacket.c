--- a/src/net/requestpacket.c
+++ b/src/net/requestpacket.c
@@ -28,7 +28,13 @@
 #include <stdint.h>
 #include <string.h>
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __cpu_to_be64 htobe64
+#define __be64_to_cpu be64toh
+#else
 #include <asm/byteorder.h>
+#endif
 
 #include "xvdr/xvdrcommand.h"
 #include "config/config.h"
