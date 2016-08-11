--- mem/shm_mem.h.orig	2016-05-30 14:13:27 UTC
+++ mem/shm_mem.h
@@ -62,6 +62,7 @@
 	#endif
 #endif
 
+#include "../error.h"
 #include "../dprint.h"
 #include "../lock_ops.h" /* we don't include locking.h on purpose */
 #include "common.h"
