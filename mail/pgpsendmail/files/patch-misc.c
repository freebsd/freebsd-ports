--- misc.c.orig	1994-12-03 17:26:58.000000000 +0900
+++ misc.c	2012-10-24 16:04:53.000000000 +0900
@@ -39,8 +39,11 @@
 
 */
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/uio.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include "pgpsendmail.h"
 
@@ -64,7 +67,9 @@
     int count = -1;
     char buffer[BUF_SIZE];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     while ( ( len = read (in_fd, buffer, BUF_SIZE) ) > 0 )
     {
@@ -195,7 +200,9 @@
     struct stat statbuf;
     char buf[BUF_SIZE];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     m_clear (buf, BUF_SIZE);
     if ( ( fd = open (filename, O_RDWR, 0) ) < 0 )
