--- thex.c.orig	Sun Sep 25 14:22:31 2005
+++ thex.c	Sun Sep 25 14:22:42 2005
@@ -37,6 +37,8 @@
 #include <string.h>
 #include <stdio.h>
 
+#define O_LARGEFILE 0
+
 int thex_tiger_root(const unsigned char* filename, uint64_t* res,
 		int use_mmap, unsigned progress_every_mib) {
 	int ret = 0;
