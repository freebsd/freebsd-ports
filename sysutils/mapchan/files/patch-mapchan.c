--- mapchan.c.orig	Sat Oct 25 09:21:42 2003
+++ mapchan.c	Sun Feb 27 15:27:01 2005
@@ -19,7 +19,7 @@
 #endif
 
 #ifndef CPATH
-  #define CPATH "/etc/mapchan"
+  #define CPATH "/usr/local/etc/mapchan"
 #endif
 
 #define BUFSIZE 4096
@@ -51,10 +51,10 @@
 
 char usage[] = { "\nUsage:\n\nmapchan [-q] [-s shell] [-f file]\
  [-h]\n\nwhere:\n\
-\tshell     - shell, if not /bin/sh
+\tshell     - shell, if not /bin/sh\n\
 \tfile      - input file\n\
-\t-q	    - force and quiet
-\t-h    - print this screen and exit.\n" };
+\t-q        - force and quiet\n\
+\t-h        - print this screen and exit.\n" };
 
 int pty_fd;     /* дескриптор master */
 int tty_fd;     /* дескриптор slave */
