--- conn_to_pgpd.c.orig	1994-12-03 12:51:16.000000000 +0900
+++ conn_to_pgpd.c	2012-10-24 16:02:51.000000000 +0900
@@ -55,6 +55,8 @@
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/uio.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include "pgpsendmail.h"
 
@@ -96,7 +98,9 @@
     char topipe_filename[STRING_LENGTH];
     char frompipe_filename[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if (gethostname (hostname, STRING_LENGTH - 1) != 0)
     {
