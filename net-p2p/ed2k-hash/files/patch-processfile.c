--- ed2k_hash/processfile.c.orig	Wed Jun 25 00:51:21 2003
+++ ed2k_hash/processfile.c	Mon Aug  9 20:39:37 2004
@@ -123,6 +123,9 @@
 		return 0;
 	}
 
+#ifndef _SC_PAGE_SIZE
+#define	_SC_PAGE_SIZE	_SC_PAGESIZE
+#endif
 	pagesize = sysconf(_SC_PAGE_SIZE);
 
 	for (b=0; b < fi.blocks; b++)
