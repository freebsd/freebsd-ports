--- ch.c.orig	2011-09-08 01:03:22.000000000 +0800
+++ ch.c	2011-09-08 01:04:33.000000000 +0800
@@ -48,6 +48,7 @@ static const char rcsid[] =
  */
 
 #include <sys/types.h>
+#include <stdlib.h>
 #include <sys/file.h>
 #include <unistd.h>
 #include <stdio.h>
@@ -391,6 +392,7 @@ ch_back_get()
  * keep==1 means keep the data in the current buffers;
  * otherwise discard the old data.
  */
+void
 ch_init(want_nbufs, keep)
 	int want_nbufs;
 	int keep;
@@ -436,7 +438,7 @@ ch_addbuf(nnew)
 {
 	register struct buf *bp;
 	register struct buf *newbufs;
-	char *calloc();
+	// char *calloc();
 
 	/*
 	 * We don't have enough buffers.
