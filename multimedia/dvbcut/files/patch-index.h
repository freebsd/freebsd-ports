--- src/index.h~	Mon Dec 19 22:52:11 2005
+++ src/index.h	Mon Dec 19 23:05:24 2005
@@ -20,7 +20,11 @@
 #define _DVBCUT_INDEX_H
 
 #include <stdint.h>
-#include <byteswap.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
+#include <byteswap.h>
+#endif
 #include "types.h"
 #include "pts.h"
 #include "defines.h"
