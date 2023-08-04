--- src/util/mercury_mem.c.orig	2023-08-04 06:03:19 UTC
+++ src/util/mercury_mem.c
@@ -24,6 +24,14 @@
 #endif
 #include <stdlib.h>
 
+#ifdef MAP_ALIGNED_SUPER
+#define MAP_HUGETLB MAP_ALIGNED_SUPER // FreeBSD
+#endif
+
+#ifndef MAP_HUGETLB
+#define MAP_HUGETLB 0
+#endif
+
 /*---------------------------------------------------------------------------*/
 long
 hg_mem_get_page_size(void)
