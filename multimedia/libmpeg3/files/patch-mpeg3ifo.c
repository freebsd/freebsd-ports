--- mpeg3ifo.c.orig
+++ mpeg3ifo.c
@@ -1,4 +1,4 @@
-#include <byteswap.h>
+//#include <byteswap.h>
 #include <dirent.h>
 #include <fcntl.h>
 #include <stdlib.h>
@@ -9,6 +9,14 @@
 #include "ifo.h"
 #include "mpeg3private.h"
 #include "mpeg3protos.h"
+
+#define bswap_16(x) ((((x) << 8) & 0xff00) | \
+		     (((x) >> 8) & 0x00ff))
+
+#define bswap_32(x) ((((x) << 24) & 0xff000000) | \
+                     (((x) <<  8) & 0x00ff0000) | \
+                     (((x) >>  8) & 0x0000ff00) | \
+                     (((x) >> 24) & 0x000000ff))
 
 typedef struct
 {
