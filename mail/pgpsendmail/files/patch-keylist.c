--- keylist.c.orig	1994-10-16 02:31:05.000000000 +0900
+++ keylist.c	2012-10-24 16:23:33.000000000 +0900
@@ -49,6 +49,9 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
+#include <ctype.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include "pgpsendmail.h"
 
@@ -74,7 +77,9 @@
     char txt[STRING_LENGTH];
     struct stat statbuf_list, statbuf_keyring;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
     static char *argv[] = {"pgp", "-kv", NULL};
 
     (void) sprintf (listfile, "%s/.keylist", pgppath);
@@ -268,7 +273,9 @@
     FILE *in_fp;
     char keyfile[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     (void) sprintf (keyfile, "%s/mypubkey.asc", pgppath);
     if ( ( in_fp = fopen (keyfile, "r") ) == NULL )
