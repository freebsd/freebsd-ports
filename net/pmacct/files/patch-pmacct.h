--- pmacct.h.orig	Thu May  8 11:59:46 2003
+++ pmacct.h	Tue May 13 10:00:09 2003
@@ -32,10 +32,6 @@
 #include <stdlib.h>
 #include <errno.h>
 
-#ifdef HAVE_GETOPT_H
-#include <getopt.h> 
-#endif
-
 #include <fcntl.h>
 #include <sys/socket.h>
 #include <sys/un.h>
