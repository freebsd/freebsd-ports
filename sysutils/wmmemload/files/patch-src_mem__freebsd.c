--- src/mem_freebsd.c.orig	2015-04-17 12:23:47 UTC
+++ src/mem_freebsd.c
@@ -10,6 +10,7 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -81,7 +82,7 @@ void mem_getusage(int *per_mem, int *per_swap, const s
 	if (swap_firsttime ||
 	    (((new_swappgsin > swappgsin) || (new_swappgsout > swappgsout))
 	     && cur_time > last_time_swap + 1)) {
-		int mib[2], n;
+		int mib[3], n;
 		size_t mibsize, size;
 		struct xswdev xsw;
 
