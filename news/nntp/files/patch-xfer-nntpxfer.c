--- xfer/nntpxfer.c.orig	Fri Dec  6 07:51:46 2002
+++ xfer/nntpxfer.c	Fri Dec  6 07:58:39 2002
@@ -107,7 +107,11 @@
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
@@ -649,8 +653,10 @@
 errmsg(code)
 int code;
 {
+#ifndef __FreeBSD__
 	extern int sys_nerr;
 	extern char *sys_errlist[];
+#endif
 	static char ebuf[6+5+1];
 
 	if (code > sys_nerr || code < 0) {
