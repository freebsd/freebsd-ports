--- src/index.h.orig	2008-10-11 20:13:37.000000000 +0900
+++ src/index.h	2009-03-27 01:33:10.000000000 +0900
@@ -22,7 +22,11 @@
 #define _DVBCUT_INDEX_H
 
 #include <stdint.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
 #include <byteswap.h>
+#endif
 #include <set>
 #include <vector>
 #include "types.h"
