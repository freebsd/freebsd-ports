--- xfer/nntpxfer.c.orig	Mon Nov  4 05:18:32 2002
+++ xfer/nntpxfer.c	Mon Nov  4 05:25:19 2002
@@ -60,6 +60,9 @@
 #include <sys/time.h>
 #endif
 
+#ifdef BSD_44
+#define _ANSI_SOURCE
+#endif
 #include <stdio.h>
 #include <errno.h>
 #include <ctype.h>
@@ -107,7 +110,11 @@
 char	*rindex();
 u_long	inet_addr();
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#else
 extern int errno;
+#endif
 char *artlist[MAX_ARTICLES];
 int server;			/* stream socket to the nntp server */
 FILE * rd_fp, * wr_fp;
