--- spawn.c.orig	1994-12-03 15:02:30.000000000 +0900
+++ spawn.c	2012-10-24 15:59:57.000000000 +0900
@@ -49,6 +49,8 @@
 
 */
 #include <stdio.h>
+#include <sys/types.h>
+#include <unistd.h>
 #include "pgpsendmail.h"
 
 
@@ -79,7 +81,9 @@
     int child_pid;
     int in_fds[2], out_fds[2], err_fds[2];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if (*in_fd < 0)
     {
