--- xfer/nntpxfer.c.orig	Thu Dec  5 10:04:30 2002
+++ xfer/nntpxfer.c	Thu Dec  5 10:07:22 2002
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
@@ -649,8 +656,10 @@
 errmsg(code)
 int code;
 {
+#ifndef __FreeBSD__
 	extern int sys_nerr;
 	extern char *sys_errlist[];
+#endif
 	static char ebuf[6+5+1];
 
 	if (code > sys_nerr || code < 0) {
