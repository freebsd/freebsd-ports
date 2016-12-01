--- src/index.h.orig	2016-11-18 13:31:01 UTC
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
