--- src/index.h.orig	2016-06-23 12:34:35 UTC
+++ src/index.h
@@ -22,7 +22,9 @@
 #define _DVBCUT_INDEX_H
 
 #include <stdint.h>
+#ifndef __FreeBSD__
 #include <byteswap.h>
+#endif
 #include <set>
 #include <vector>
 #include "types.h"
