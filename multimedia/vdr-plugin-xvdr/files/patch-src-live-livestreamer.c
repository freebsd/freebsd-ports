--- a/src/live/livestreamer.c
+++ b/src/live/livestreamer.c
@@ -29,7 +29,12 @@
 #include <map>
 #include <vdr/remux.h>
 #include <vdr/channels.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __cpu_to_be64 htobe64
+#else
 #include <asm/byteorder.h>
+#endif
 
 #include "config/config.h"
 #include "net/cxsocket.h"
