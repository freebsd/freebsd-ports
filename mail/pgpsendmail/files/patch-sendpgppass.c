--- sendpgppass.c.orig	1994-12-03 13:10:21.000000000 +0900
+++ sendpgppass.c	2012-10-24 16:22:30.000000000 +0900
@@ -56,13 +56,15 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #ifdef _AIX
 #  include <termios.h>
 #  include <termio.h>
 #else
-#  include <sys/termios.h>
+#  include <termios.h>
 #endif
 #include <fcntl.h>
 #include "pgpsendmail.h"
@@ -96,7 +98,7 @@
 STATIC_FUNCTION (char *get_userid, (char *pgppath) );
 
 
-void main (argc, argv, envp)
+int main (argc, argv, envp)
 int argc;
 char *argv[];
 char *envp[];
@@ -118,7 +120,9 @@
     char txt[STRING_LENGTH];
     char *pgp_argv[7];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if ( ( pgppath = getenv ("PGPPATH") ) == NULL )
     {
@@ -323,7 +327,9 @@
     int count;
     int fd;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
     static char buffer[STRING_LENGTH];
 
     if ( ( fd = open (TTY, O_RDWR, 0) ) < 0 )
@@ -395,7 +401,9 @@
     char config_filename[STRING_LENGTH];
     char txt[STRING_LENGTH];
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     (void) sprintf (config_filename, "%s/PGPdaemon.config", pgppath);
     if ( ( fp = fopen (config_filename, "r") ) == NULL )
